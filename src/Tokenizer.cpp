#include <iostream>
#include <string>
#include <vector>
#include "Tokenizer.hpp"

namespace lexer {
    std::vector<Token> Tokenizer::tokenize(const std::string &inProgram){
        std::vector<Token> tokens;
        Token currentToken;

        currentToken.LineNumber = 1;
        for (size_t i = 0; i < inProgram.size(); ++i)
        {
            char currCh = inProgram[i];

            if(currentToken.Type == STRING_ESCAPE_SEQUENCE)
            {
                switch(currCh)
                {
                    case 'n':
                        currentToken.text.append(1, '\n');
                        break;
                    case 'r':
                        currentToken.text.append(1, '\r');
                        break;
                    case 't':
                        currentToken.text.append(1, '\t');
                        break;
                    case '\\':
                        currentToken.text.append(1, '\\');
                        break;
                    default:
                        throw std::runtime_error(std::string("Unknown escape sequence: " + std::string(1, currCh) + " in string on line" 
                            + std::to_string(currentToken.LineNumber) + "."));
                        break;
                }
                currentToken.Type = STRING_LITERAL;
                continue;
            }
            
            
            switch(currCh)
            {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if(currentToken.Type == WHITESPACE)
                    {
                        currentToken.Type = INTEGER_LITERAL;
                        currentToken.text.append(1, currCh);
                    
                    } 
                    else if(currentToken.Type == POTENTIAL_DOUBLE)
                    {
                        currentToken.Type = DOUBLE_LITERAL;
                        currentToken.text.append(1, currCh);
                    } 
                    else 
                    {
                        currentToken.text.append(1, currCh);
                    }
                    break;
                
                case '.':
                    if(currentToken.Type == WHITESPACE)
                    {
                        currentToken.Type = POTENTIAL_DOUBLE;
                        currentToken.text.append(1, currCh);
                    } 
                    else if(currentToken.Type == INTEGER_LITERAL)
                    {
                        currentToken.Type = DOUBLE_LITERAL;
                        currentToken.text.append(1, currCh);
                    }
                    else if(currentToken.Type == STRING_LITERAL)
                    {
                        currentToken.text.append(1, currCh);
                    }
                    else
                    {
                        endToken(currentToken, tokens);
                        currentToken.Type = OPERATOR;
                        currentToken.text.append(1, currCh);
                        endToken(currentToken, tokens);
                    }
                    break;
                
                case '{':
                case '}':
                case '(':
                case ')':
                case '=':
                case '-':
                case ';':
                case ',':
                    if(currentToken.Type != STRING_LITERAL)
                    {
                        endToken(currentToken, tokens);
                        currentToken.Type = OPERATOR;
                        currentToken.text.append(1, currCh);
                        endToken(currentToken, tokens);
                    } 
                    else 
                    {
                        currentToken.text.append(1, currCh);
                    }
                    break;
                
                case ' ':
                case '\t':
                    endToken(currentToken, tokens);
                    break;
                case '\r':
                case '\n':
                    ++currentToken.LineNumber;
                    break;
                case '"':
                    endToken(currentToken, tokens); // Start of string
                    currentToken.Type = STRING_LITERAL;
                    currentToken.text = "\""; // Include the opening quote
                    while (++i < inProgram.size()) {
                        char nextCh = inProgram[i];
                        currentToken.text.append(1, nextCh);
                        if (nextCh == '"') {
                            break; // End of string
                        }
                        // Handle escape sequences here if needed
                    }
                    endToken(currentToken, tokens);
                    continue;
                
                case '\\':
                    if(currentToken.Type == STRING_LITERAL)
                    {
                        currentToken.Type = STRING_ESCAPE_SEQUENCE;
                        currentToken.text.append(1, currCh);
                    } 
                    else 
                    {
                        endToken(currentToken, tokens);
                        currentToken.Type = OPERATOR;
                        currentToken.text.append(1, currCh);
                        endToken(currentToken, tokens);
                    }
                    break;

                case '/':
                    if(currentToken.Type == STRING_LITERAL)
                    {
                        currentToken.text.append(1, currCh);
                    }
                    else if(currentToken.Type == POTENTIAL_COMMENT)
                    {
                        currentToken.Type = COMMENT;
                        currentToken.text.erase();
                    }
                    else
                    {
                        endToken(currentToken, tokens);
                        currentToken.Type = POTENTIAL_COMMENT;
                        currentToken.text.append(1, currCh);
                    }
                    break;
                default:
                    if(currentToken.Type == WHITESPACE || currentToken.Type == INTEGER_LITERAL
                        || currentToken.Type == DOUBLE_LITERAL)
                    {
                        endToken(currentToken, tokens);
                        currentToken.Type = IDENTIFIER;
                        currentToken.text.append(1, currCh);
                    }
                    else
                    {
                        currentToken.text.append(1, currCh);
                    }
                    break;

            }
        }

        endToken(currentToken, tokens);

        return tokens;
    }

    void Tokenizer::endToken(Token &token, std::vector<Token> &tokens){
        if(token.Type != WHITESPACE)
        {
            tokens.push_back(token);
        }
        else if(token.Type == POTENTIAL_DOUBLE)
        {
            token.Type = DOUBLE_LITERAL;

        }
        token.Type = WHITESPACE;
        token.text.erase();

    }
}
