#include <iostream>
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/IRReader/IRReader.h"
//#include <llvm/IRReader/IRReader.h>
//#include <llvm/IR/LLVMContext.h>
//#include <llvm/IR/Function.h>
//#include <llvm/Bitcode/BitcodeWriter.h>
//#include <llvm/Support/raw_ostream.h>

// using namespace std;
// using namespace llvm;

void TraverseModule(void);

llvm::LLVMContext* TheContext;
std::unique_ptr<llvm::Module> TheModule;

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

    std::cout << "Success reading & parsing the IR file." << std::endl;
    std::cout << "The module name is \"" << TheModule->getName().str() << "\"" << std::endl;
    std::cout << std::endl;
    return 0;
}

void TraverseModule(void) {
    llvm::raw_os_ostream raw_cout( std::cout );

    for( llvm::Module::iterator ModIter = TheModule->begin(); ModIter != TheModule->end(); ++ModIter ) {
        llvm::Function* Func = llvm::cast<llvm::Function>(ModIter);

        raw_cout << Func->getName() << '\n';

        for( llvm::Function::iterator FuncIter = Func->begin(); FuncIter != Func->end(); ++FuncIter ) {
            llvm::BasicBlock* BB = llvm::cast<llvm::BasicBlock>(FuncIter);

            for( llvm::BasicBlock::iterator BBIter = BB->begin(); BBIter != BB->end(); ++BBIter ) {
                llvm::Instruction* Inst = llvm::cast<llvm::Instruction>(BBIter);

                raw_cout << '\t';
                Inst->print(raw_cout);
                raw_cout << '\n';
            }
        }
    }
}
