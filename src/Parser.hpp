#pragma once

#include "Tokenizer.hpp"
#include <vector>

namespace parser {
    class Parser {
    public:
        Parser(const std::vector<lexer::Token>& tokens);
        void parse();
    private:
        std::vector<lexer::Token> tokens;
        size_t current;
    };
}
