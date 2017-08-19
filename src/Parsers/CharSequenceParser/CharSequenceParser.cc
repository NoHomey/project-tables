#include "CharSequenceParser.h"

bool CharSequenceParser::isWhiteSpace(char symbol) noexcept {
    return (symbol == ' ') ||(symbol == '\t');
}

CharSequenceParser::ParseResult::ParseResult(ConstString& extracted, ConstString& rest) noexcept
: extracted{extracted}, rest{rest} { }

ConstString& CharSequenceParser::ParseResult::getExtracted() const noexcept {
    return extracted;
}

ConstString& CharSequenceParser::ParseResult::getRest() const noexcept {
    return rest;
}

CharSequenceParser::ParseResult CharSequenceParser::parseSeparatedByWhiteSpaces(ConstString& string) {
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
    size_t length = offset;
    char symbol;
    do {
        ++length;
        symbol = string[length];
    } while(!isWhiteSpace(symbol) && (symbol != '\0'));
    return {{string, offset, length - offset}, {string, length}};
}