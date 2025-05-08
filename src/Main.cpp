#include <iostream>
#include <fstream>
#include <sstream>
#include "Tokenizer.hpp"
#include "Parser.hpp"

int main() {
    std::ifstream inFile("../../test.lua");
    if (!inFile) {
        std::cerr << "Failed to open test.lua\n";
        return 1;
    }
    
    std::stringstream buffer;
    buffer << inFile.rdbuf();

    lexer::Tokenizer tokenizer;
    auto tokens = tokenizer.tokenize(buffer.str());

    parser::Parser parser(tokens);
    parser.parse();

    return 0;
}