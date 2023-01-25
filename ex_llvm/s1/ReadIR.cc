#include <iostream>
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/SourceMgr.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Function.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/raw_ostream.h>

// using namespace std;
// using namespace llvm;

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

    std::cout << "Success reading & parsing the IR file." << std::endl;
    std::cout << "The module name is \"" << TheModule->getName().str() << "\"" << std::endl;
    std::cout << std::endl;
    return 0;
}
