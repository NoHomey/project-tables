#include "CharSequenceParser.h"

bool CharSequenceParser::isWhiteSpace(char symbol) noexcept {
    return (symbol == ' ') ||(symbol == '\t');
}

CharSequenceParser::ParseResult CharSequenceParser::parseSeparatedByWhiteSpaces(ConstString& string) noexcept {
    size_t offset = 0;
    while(isWhiteSpace(string[offset])) {
        ++offset;
    }
    size_t length = offset;
    char symbol;
    do {
        ++length;
        symbol = string[length];
    } while(!isWhiteSpace(symbol) && (symbol != '\0'));
    return {{string, offset, length - offset}, {string, length}};
}