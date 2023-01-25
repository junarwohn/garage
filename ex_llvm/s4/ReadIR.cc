#include <iostream>
#include <string>
#include <vector>
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/IR/InstrTypes.h"

#include "llvm/ADT/APInt.h"
#include "llvm/IR/Verifier.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/IR/Argument.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <unordered_map>
#include <string>

//#include <llvm/IRReader/IRReader.h>
//#include <llvm/IR/LLVMContext.h>
//#include <llvm/IR/Function.h>
//#include <llvm/Bitcode/BitcodeWriter.h>
//#include <llvm/Support/raw_ostream.h>

// using namespace std;
// using namespace llvm;

void TraverseModule(void);
void printInst(void);

llvm::LLVMContext* TheContext;
std::unique_ptr<llvm::Module> TheModule;

int inst_cnt[9];

std::string inst_name[9] = {
    "Add",
    "FAdd",
    "Sub",
    "FSub",
    "Mul",
    "FMul",
    "UDiv",
    "SDiv",
    "FDiv",
};

std::unordered_map<std::string, int> func_cnt;

int main(int argc, char** argv) {
    std::string input_path;
    llvm::SMDiagnostic err;

    if (argc < 2) {
        std::cout << "Usage: ./ReadIR <ir_file_path>" << std::endl;
        return -1;
    }

    input_path = std::string(argv[1]);

    TheContext = new llvm::LLVMContext();
    if (!TheContext) {
        std::cout  << "fail to allocate LLVMContext" << std::endl;
        return -1;
    }

    TheModule = llvm::parseIRFile(input_path, err, *TheContext);
    if (!TheModule) {
        std::cout << "cannot open the file" << input_path << std::endl;
        return -1;
    }

    TraverseModule();
    printInst();

    /*  
        std::cout << "Success reading & parsing the IR file." << std::endl;
        std::cout << "The module name is \"" << TheModule->getName().str() << "\"" << std::endl;
        std::cout << std::endl;
        for (int i = 0 ; i < 9; ++i) {
        std::cout << "Number of " << inst_name[i] << " instruction : " << inst_cnt[i] << '\n';
        }

        for (auto m : func_cnt) {
        std::cout << m.first << " " << m.second << "\n";
        }
        */
    return 0;

}

void TraverseModule(void) {
    std::string func_name;
    llvm::raw_os_ostream raw_cout( std::cout );

    int op_code;
    for( llvm::Module::iterator ModIter = TheModule->begin(); ModIter != TheModule->end(); ++ModIter ) {
        llvm::Function* Func = llvm::cast<llvm::Function>(ModIter);


        for( llvm::Function::iterator FuncIter = Func->begin(); FuncIter != Func->end(); ++FuncIter ) {
            llvm::BasicBlock* BB = llvm::cast<llvm::BasicBlock>(FuncIter);

            std::vector< llvm::Instruction* > AddInsts;
            std::vector< llvm::Instruction* > ToDeleteInsts;
            for( llvm::BasicBlock::iterator BBIter = BB->begin(); BBIter != BB->end(); ++BBIter ) {
                llvm::Instruction* Inst = llvm::cast<llvm::Instruction>(BBIter);

                if (auto *CB = llvm::dyn_cast<llvm::CallInst>(Inst)) {
                    func_name = CB->getCalledFunction()->getName();
                    if (func_cnt.find(func_name) != func_cnt.end()) {
                        func_cnt.find(func_name)->second += 1;
                    } else {
                        func_cnt[func_name] = 1;
                    }
                }

                if ( Inst->getOpcode() == llvm::Instruction::Add ) {
                    if ( Inst->getNextNode()->getOpcode() == llvm::Instruction::Add && Inst->getNextNode()->getOperand(0) == Inst ) {

                        llvm::Instruction* nextInst = Inst->getNextNode();
                       // raw_cout << "Operand 0 : " << Inst->getOperand(0) << " Operand 1 : " << Inst->getOperand(1) <<  " dest : " << Inst<<  "\n";
                       // raw_cout << "Operand 0 : " << nextInst->getOperand(0) << " Operand 1 : " << nextInst->getOperand(1)  << " dest : " << nextInst <<  "\n";
                        //raw_cout << *Inst << "\n";
                        //raw_cout << *nextInst << "\n";
                        if ( Inst == nextInst->getOperand(0) ) {


                            llvm::Instruction* MulInst = llvm::BinaryOperator::Create(
                                    llvm::Instruction::Mul,
                                    Inst->getOperand(0),
                                    Inst->getOperand(1),
                                    "multmp",
                                    nextInst 
                                    );

                            llvm::Instruction* SubInst = llvm::BinaryOperator::Create(
                                    llvm::Instruction::Sub,
                                    MulInst,
                                    nextInst->getOperand(1),
                                    "subtmp",
                                    nextInst
                                    );

                            nextInst->replaceAllUsesWith( SubInst );
                            ToDeleteInsts.push_back( Inst );
                            ToDeleteInsts.push_back( nextInst );
                        }
                    }
                    //llvm::Instruction* SubInst = llvm::BinaryOperator::Create(
                    //        llvm::Instruction::Sub,
                    //        Inst->getOperand(0),
                    //        Inst->getOperand(1),
                    //        "subtmp",
                    //        Inst

                    //        );
                    //Inst->replaceAllUsesWith( SubInst );
                    //AddInsts.push_back( Inst );
                }


                //                if ( Inst->getOpcode() == llvm::Instruction::Add ) {
                //                    llvm::BinaryOperator::Create(
                //                            llvm::Instruction::Add,
                //                            llvm::ConstantInt::get( llvm::IntegerType::get( *TheContext, 32 ), 1, true ),
                //                            llvm::ConstantInt::get( llvm::IntegerType::get( *TheContext, 32 ), 1, true ),
                //                            "addtmp",
                //                            Inst
                //                   
                //                            );
                //                }

                op_code = Inst->getOpcode();
                if (llvm::Instruction::Add <= op_code && op_code <= llvm::Instruction::FDiv) {
                    inst_cnt[op_code - llvm::Instruction::Add]++;                    
                }
            }
            for( int i = 0, Size=AddInsts.size(); i < Size; ++i) { AddInsts[i]->eraseFromParent();}
            for( int i = 0, Size=ToDeleteInsts.size(); i < Size; ++i) { ToDeleteInsts[i]->eraseFromParent();}
        }
    }
}

void printInst(void) {
    llvm::raw_os_ostream raw_cout( std::cout );

    raw_cout << *TheModule;

    //for( llvm::Module::iterator ModIter = TheModule->begin(); ModIter != TheModule->end(); ++ModIter ) {
    //    llvm::Function* Func = llvm::cast<llvm::Function>(ModIter);

    //    for( llvm::Function::iterator FuncIter = Func->begin(); FuncIter != Func->end(); ++FuncIter ) {
    //        llvm::BasicBlock* BB = llvm::cast<llvm::BasicBlock>(FuncIter);

    //        for( llvm::BasicBlock::iterator BBIter = BB->begin(); BBIter != BB->end(); ++BBIter ) {
    //            llvm::Instruction* Inst = llvm::cast<llvm::Instruction>(BBIter);

    //            raw_cout << '\t';
    //            Inst->print(raw_cout);
    //            raw_cout << '\n';
    //        }
    //    }
    //}
}
