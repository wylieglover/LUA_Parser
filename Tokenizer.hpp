#include <vector>
#include <string>

namespace parser{
    using namespace std;
    
    enum TokenType{
        WHITESPACE, // Token never has this type
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
        enum TokenType Type{WHITESPACE};
        string text;
        size_t StartOffset{0};
        size_t EndOffset{0};
        size_t LineNumber{0};
    };

    class Tokenizer{
    public:
        vector<Token> parse(const string &inProgram);

    private:
        void endToken(Token &token, vector<Token> &tokens);
    };
}