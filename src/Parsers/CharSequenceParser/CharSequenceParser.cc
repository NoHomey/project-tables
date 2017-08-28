#include "CharSequenceParser.h"
#include "../../NullText.h"

CharSequenceParser::Null::Null(ConstString& rest) noexcept
: TokenException{rest} { }

bool CharSequenceParser::isWhiteSpace(char symbol) noexcept {
    return (symbol == ' ') ||(symbol == '\t');
}

bool CharSequenceParser::isEndOfLine(char symbol) noexcept {
    return symbol == '\n';
}

bool CharSequenceParser::isDelimiter(char symbol) noexcept {
    return isWhiteSpace(symbol) || isEndOfLine(symbol) || (symbol == '\0');
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

CharSequenceParser::ParseResult CharSequenceParser::parseSeparatedByWhiteSpaces(ConstString& string, bool throwNull) {
    const size_t offset = skipWhiteSpaces(string);
    size_t length = offset;
    char symbol;
    do {
        ++length;
        symbol = string[length];
    } while(!isDelimiter(symbol));
    ConstString extracted = {string, offset, length - offset};
    ConstString rest = {string, length};
    if(throwNull && (extracted == NullText)) {
        throw Null{rest};
    }
    return {extracted, rest};
}