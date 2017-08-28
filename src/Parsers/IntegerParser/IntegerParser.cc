#include "IntegerParser.h"
#include "../../Table/TableTypes/StringifiedIntegerLimits.h"

IntegerParser::SingleSign::SingleSign(char sign) noexcept
: sign{sign} { }

char IntegerParser::SingleSign::getSign() const noexcept {
    return sign;
}

IntegerParser::InvalidInteger::InvalidInteger(size_t position, char symbol, ConstString& token) noexcept
: InvalidSymbolAtPosition{position, symbol, token} { }

IntegerParser::MaxLimit::MaxLimit(ConstString& token) noexcept
: TokenException{token} { }

IntegerParser::MinLimit::MinLimit(ConstString& token) noexcept
: TokenException{token} { }

IntegerParser::ParseResult::ParseResult() noexcept
: Base{0} { }

IntegerParser::ParseResult::ParseResult(TableTypes::Integer integer, ConstString& rest) noexcept
: Base{integer, rest} { }

IntegerParser::ParseResult::ParseResult(std::nullptr_t, ConstString& rest) noexcept
: Base{nullptr, rest} { }

bool IntegerParser::isMinus(char symbol) noexcept {
    return symbol == '-';
}

bool IntegerParser::isPlus(char symbol) noexcept {
    return symbol == '+';
}

bool IntegerParser::isSign(char symbol) noexcept {
    return isMinus(symbol) || isPlus(symbol);
}

bool IntegerParser::isDigit(char symbol) noexcept {
    return (symbol >= '0') && (symbol <= '9');
}

bool IntegerParser::isZero(char symbol) noexcept {
    return symbol == '0';
}

ConstString IntegerParser::skipLeadingZeros(ConstString& string) noexcept {
    size_t index = 0;
    while(isZero(string[index])) {
        ++index;
    }
    return {string, index};
}

void IntegerParser::ensureOnlyDigits(ConstString& string, ConstString& token, size_t offset) {
    const size_t length = string.length();
    char symbol;
    for(size_t index = 0; index < length; ++index) {
        symbol = string[index];
        if(!isDigit(symbol)) {
            throw InvalidInteger{index + offset, symbol, token};
        }
    }
}

void IntegerParser::ensureInLimits(bool isNegative, ConstString& digitSequence, ConstString& token) {
    if(digitSequence.length() < StringifiedIntegerLimits::DigitsCountOfMin) {
        return;
    }
    if(digitSequence.length() > StringifiedIntegerLimits::DigitsCountOfMin) {
        if(isNegative) {
            throw MinLimit{token};
        } else {
            throw MaxLimit{token};
        }
    }
    if(isNegative) {
        if(digitSequence > ConstString{StringifiedIntegerLimits::Min, 1}) {
            throw MinLimit{token};
        }
    } else if(digitSequence > StringifiedIntegerLimits::Max) {
        throw MaxLimit{token};
    }
}

unsigned char IntegerParser::toDigit(char symbol) noexcept {
    return isDigit(symbol) ? (symbol - '0') : symbol;
}

TableTypes::Integer IntegerParser::parseInteger(bool isNegative, ConstString& digitSequence) noexcept {
    size_t index = 0;
    char currentSymbol = digitSequence[index];
    TableTypes::Integer integer = 0;
    while(currentSymbol != '\0') {
        integer *= 10;
        integer += toDigit(currentSymbol);
        ++index;
        currentSymbol = digitSequence[index];
    }
    return isNegative ? (-integer) : integer;
}

IntegerParser::Processed IntegerParser::commonProcess(ConstString& string) {
    CharSequenceParser::ParseResult result = CharSequenceParser::parseSeparatedByWhiteSpaces(string, true);
    ConstString& extracted = result.getParsed();
    const bool hasSign = isSign(extracted[0]);
    const bool isNegative = isMinus(extracted[0]);
    if(hasSign && (extracted.length() == 1)) {
        throw SingleSign{extracted[0]};
    }
    ConstString digitSequence = skipLeadingZeros({extracted, hasSign});
    return {
        extracted.length() - digitSequence.length(),
        extracted,
        digitSequence,
        result.getRest(),
        hasSign,
        isNegative
    };
}

IntegerParser::ParseResult IntegerParser::parse(ConstString& string) {
    Processed processed;
    try {
        processed = commonProcess(string);
    } catch(const CharSequenceParser::Null& error) {
        return {nullptr, error.getToken()};
    }
    if(processed.digitSequence.length() == 0) {
        return {static_cast<TableTypes::Integer>(0), processed.rest};
    }
    ensureOnlyDigits(processed.digitSequence, processed.extracted, processed.offset);
    ensureInLimits(processed.isNegative, processed.digitSequence, processed.extracted);
    return {parseInteger(processed.isNegative, processed.digitSequence), processed.rest};
}