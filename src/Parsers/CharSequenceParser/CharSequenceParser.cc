#include "CharSequenceParser.h"

bool CharSequenceParser::isWhiteSpace(char symbol) noexcept {
    return (symbol == ' ') ||(symbol == '\t');
}

bool CharSequenceParser::isEndOfLine(char symbol) noexcept {
    return symbol == '\n';
}

CharSequenceParser::ParseResult::ParseResult(ConstString& extracted, ConstString& rest) noexcept
: Base{extracted, rest} { }

size_t CharSequenceParser::skipWhiteSpaces(ConstString& string) {
    const size_t stringLength = string.length();
    if(stringLength == 0) {
        throw EmptyString{};
    }
    size_t offset = 0;
    while(isWhiteSpace(string[offset])) {
        ++offset;
    }
    if(stringLength == offset) {
        throw  NoCharSequenceFound{};
    }
    return offset;
}

CharSequenceParser::ParseResult CharSequenceParser::parseSeparatedByWhiteSpaces(ConstString& string) {
    const size_t offset = skipWhiteSpaces(string);
    size_t length = offset;
    char symbol;
    do {
        ++length;
        symbol = string[length];
    } while(!isWhiteSpace(symbol) && !isEndOfLine(symbol) && (symbol != '\0'));
    return {{string, offset, length - offset}, {string, length}};
}