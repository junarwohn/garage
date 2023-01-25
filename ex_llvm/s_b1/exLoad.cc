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

    std::vector< llvm::Instruction* > ToEraseInsts;
    int op_code;
    for( llvm::Module::iterator ModIter = TheModule->begin(); ModIter != TheModule->end(); ++ModIter ) {
        llvm::Function* Func = llvm::cast<llvm::Function>(ModIter);


        for( llvm::Function::iterator FuncIter = Func->begin(); FuncIter != Func->end(); ++FuncIter ) {
            llvm::BasicBlock* BB = llvm::cast<llvm::BasicBlock>(FuncIter);

            std::vector< llvm::Instruction* > ToEraseInsts;
            for( llvm::BasicBlock::iterator BBIter = BB->begin(); BBIter != BB->end(); ++BBIter ) {
                llvm::Instruction* Inst = llvm::cast<llvm::Instruction>(BBIter);

                op_code = Inst->getOpcode();
                if ( 
                        ( op_code == llvm::Instruction::Add &&
                            llvm::isa<llvm::Constant>(Inst->getOperand(1)) && 
                            llvm::dyn_cast<llvm::ConstantInt>(Inst->getOperand(1))->getSExtValue() == 0)
                        ||
                        ( op_code == llvm::Instruction::Mul &&
                            llvm::isa<llvm::Constant>(Inst->getOperand(1)) && 
                            llvm::dyn_cast<llvm::ConstantInt>(Inst->getOperand(1))->getSExtValue() == 1)
                        ) {
                    Inst->replaceAllUsesWith(Inst->getOperand(0));

                    ToEraseInsts.push_back(Inst);
                }
            }

            for( int i = 0, Size=ToEraseInsts.size(); i < Size; ++i) { ToEraseInsts[i]->eraseFromParent();}
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
