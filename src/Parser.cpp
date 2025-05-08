#include "Parser.hpp"
#include <iostream>

namespace parser {
    Parser::Parser(const std::vector<lexer::Token>& tokens)
        : tokens(tokens), current(0) {}

    void Parser::parse() {
        std::cout << "Parsing " << tokens.size() << " tokens..." << std::endl;
        for (const auto& token : tokens) {
            std::cout << "Token: " << token.text << " (Type: " << token.Type << ")\n";
        }
    }

}
