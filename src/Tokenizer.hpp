#pragma once

#include <string>
#include <vector>

namespace lexer {
    enum TokenType {
        WHITESPACE,
        IDENTIFIER,
        INTEGER_LITERAL,
        STRING_LITERAL,
        OPERATOR,
        STRING_ESCAPE_SEQUENCE,
        POTENTIAL_DOUBLE,
        DOUBLE_LITERAL,
        POTENTIAL_COMMENT,
        COMMENT
    };

    class Token {
    public:
        TokenType Type{WHITESPACE};
        std::string text;
        size_t StartOffset{0};
        size_t EndOffset{0};
        size_t LineNumber{0};
    };

    class Tokenizer {
    public:
        std::vector<Token> tokenize(const std::string &inProgram);
    private:
        void endToken(Token &token, std::vector<Token> &tokens);
    };
}
