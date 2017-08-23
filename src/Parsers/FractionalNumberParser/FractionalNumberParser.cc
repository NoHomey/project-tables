#include "FractionalNumberParser.h"
#include "../../Table/TableTypes/FractionalNumber.h"

FractionalNumberParser::DigitsCountLimit::DigitsCountLimit(ConstString& token) noexcept
: TokenException{token} { }

FractionalNumberParser::FractionaNumberHasNoIntegerPart::FractionaNumberHasNoIntegerPart(ConstString& token) noexcept
: TokenException{token} { }

FractionalNumberParser::IncompleteFractionaNumber::IncompleteFractionaNumber(ConstString& token) noexcept
: TokenException{token} { }

FractionalNumberParser::ParseResult::ParseResult() noexcept
: Base{0} { }

FractionalNumberParser::ParseResult::ParseResult(TableTypes::FractionalNumber fractionalNumber, ConstString& rest) noexcept
: Base{fractionalNumber, rest} { }

bool FractionalNumberParser::isFloatingPoint(char symbol) noexcept {
    return symbol == '.';
}

size_t FractionalNumberParser::findFirstFloatingPointIndex(ConstString& string) noexcept {
    const size_t length = string.length();
    for(size_t index = 0; index < length; ++index) {
        if(isFloatingPoint(string[index])) {
            return index;
        }
    }
    return length;
}

TableTypes::FractionalNumber FractionalNumberParser::parseFractionalNumber(
    bool isNegative, ConstString& integerPart, ConstString& fractionalPart
) noexcept {
    const TableTypes::Integer integerParsed = parseInteger(isNegative, integerPart);
    long long floatingPart = 0;
    unsigned long long floatingExponent = 1;
    size_t index = 0;
    char currentSymbol = fractionalPart[index];
    while(currentSymbol != '\0') {
        if((floatingPart != 0) || (!isZero(currentSymbol))) {
            floatingPart *= 10;
            floatingPart += toDigit(currentSymbol);
        }
        floatingExponent *= 10;
        ++index;
        currentSymbol = fractionalPart[index];
    }
    const TableTypes::FractionalNumber fractionalParsed = 
                        static_cast<TableTypes::FractionalNumber>(floatingPart)
                                    / 
                        static_cast<TableTypes::FractionalNumber>(floatingExponent);

    return static_cast<TableTypes::FractionalNumber>(integerParsed) + fractionalParsed;
}

FractionalNumberParser::ParseResult FractionalNumberParser::parse(ConstString& string) {
    Processed processed = commonProcess(string);
    if(processed.digitSequence.length() == 0) {
        return {0, processed.rest};
    }
    ConstString number = isZero(processed.extracted[processed.hasSign]) && isFloatingPoint(processed.digitSequence[0])
        ? ConstString{processed.extracted, processed.offset - 1} : processed.digitSequence;
    const size_t firstFloatingPointIndex = findFirstFloatingPointIndex(number);
    if(firstFloatingPointIndex == 0) {
        if(processed.extracted.length() == 1) {
            throw SingleFloatingPoint{};
        }
        throw FractionaNumberHasNoIntegerPart{processed.extracted};
    }
    if(number.length() == (firstFloatingPointIndex + 1)) {
        throw IncompleteFractionaNumber{processed.extracted};
    }
    ConstString integerPart{number, 0, firstFloatingPointIndex};
    ConstString fractionalPart{number, firstFloatingPointIndex + 1};
    ensureOnlyDigits(integerPart, processed.extracted, processed.offset);
    ensureOnlyDigits(fractionalPart, processed.extracted, processed.offset + firstFloatingPointIndex);
    if((integerPart.length() + fractionalPart.length()) > FractionalNumber::MaxOfDigitsCount) {
        throw DigitsCountLimit{processed.extracted};
    }
    return {parseFractionalNumber(processed.isNegative, integerPart, fractionalPart), processed.rest};
}