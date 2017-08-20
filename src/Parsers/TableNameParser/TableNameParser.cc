#include "TableNameParser.h"

TableNameParser::InvalidTableName::InvalidTableName(size_t position, char symbol, ConstString& token) noexcept
: InvalidSymbolAtPosition{position, symbol, token} { }

bool TableNameParser::isLowerCaseLetter(char symbol) noexcept {
    return (symbol >= 'a') && (symbol <= 'z');
}

bool TableNameParser::isUpperCaseLetter(char symbol) noexcept {
    return (symbol >= 'A') && (symbol <= 'Z');
}

bool TableNameParser::isLetter(char symbol) noexcept {
    return isLowerCaseLetter(symbol) || isUpperCaseLetter(symbol);
}

bool TableNameParser::isDigit(char symbol) noexcept {
    return (symbol >= '0') && (symbol <= '9');
}

bool TableNameParser::isDash(char symbol) noexcept {
    return symbol == '-';
}

bool TableNameParser::isUnderscore(char symbol) noexcept {
    return symbol == '_';
}

bool TableNameParser::isDolarSign(char symbol) noexcept {
    return symbol == '$';
}

bool TableNameParser::isHashSymbol(char symbol) noexcept {
    return symbol == '#';
}

bool TableNameParser::isFirstValid(char symbol) noexcept {
    return isLetter(symbol);
}

bool TableNameParser::isSubsequentValid(char symbol) noexcept {
    return isLetter(symbol) || isDigit(symbol) || isDash(symbol)
        || isUnderscore(symbol) || isDolarSign(symbol) || isHashSymbol(symbol);
}

CharSequenceParser::ParseResult TableNameParser::parse(ConstString& string) {
    CharSequenceParser::ParseResult result = CharSequenceParser::parseSeparatedByWhiteSpaces(string);
    ConstString& extracted = result.getExtracted();
    char symbol = extracted[0];
    if(!isFirstValid(symbol)) {
        throw InvalidTableName{0, symbol, extracted};
    }
    const size_t extractedLength = extracted.length();
    for(size_t index = 2; index < extractedLength; ++index) {
        symbol = extracted[index];
        if(!isSubsequentValid(symbol)) {
            throw InvalidTableName{index, symbol, extracted};
        }
    }
    return result;
}