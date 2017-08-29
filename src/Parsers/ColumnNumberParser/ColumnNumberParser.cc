#include "ColumnNumberParser.h"
#include "../../NullText.h"

ColumnNumberParser::InvalidColumnNumber::InvalidColumnNumber(size_t position, char symbol, ConstString& token) noexcept
: InvalidSymbolAtPosition{position, symbol, token} { }

ColumnNumberParser::InvalidColumnNumber::InvalidColumnNumber(const InvalidSymbolAtPosition& error) noexcept
: InvalidSymbolAtPosition{error} { }

ColumnNumberParser::HasSign::HasSign(ConstString& token) noexcept
: TokenException{token} { }

ColumnNumberParser::ParseResult::ParseResult() noexcept
: Base{0} { }

ColumnNumberParser::ParseResult::ParseResult(TableTypes::Column columnNumber, ConstString& rest) noexcept
: Base{columnNumber, rest} { }

ColumnNumberParser::ParseResult ColumnNumberParser::parse(ConstString& string) {
    Processed processed = commonProcess(string);
    if(processed.hasSign) {
        throw HasSign{processed.extracted};
    }
    if(processed.digitSequence.length() == 0) {
        throw IsZero{};
    }
    try {
        ensureOnlyDigits(processed.digitSequence, processed.extracted, processed.offset);
    } catch(const InvalidInteger& error) {
        throw InvalidColumnNumber{error};
    }
    ensureInLimits(processed.isNegative, processed.digitSequence, processed.extracted);
    TableTypes::Integer integer = parseInteger(processed.isNegative, processed.digitSequence);
    if(integer > Max) {
        throw MaxLimit{processed.extracted};
    }
    return {static_cast<TableTypes::Column>(integer), processed.rest};
}