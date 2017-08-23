#include "ColumnNumberParser.h"

ColumnNumberParser::MaxLimit::MaxLimit(ConstString& token) noexcept
: TokenException{token} { }

ColumnNumberParser::MinLimit::MinLimit(ConstString& token) noexcept
: TokenException{token} { }

ColumnNumberParser::ParseResult::ParseResult() noexcept
: Base{0} { }

ColumnNumberParser::ParseResult::ParseResult(TableTypes::Column columnNumber, ConstString& rest) noexcept
: Base{columnNumber, rest} { }

ColumnNumberParser::ParseResult ColumnNumberParser::parse(ConstString& string) {
    IntegerParser::ParseResult result;
    try {
        result = IntegerParser::parse(string);
    } catch(const IntegerParser::SingleSign& error) {
        if(error.getSign() == '-') {
            throw SingleMinus{};
        } 
        throw SinglePlus{};
    } catch(const IntegerParser::MinLimit& error) {
        throw MinLimit{error.getToken()};
    } catch(const IntegerParser::MaxLimit& error) {
        throw MaxLimit{error.getToken()};
    }
    TableTypes::Integer integer = result.getParsed();
    if(integer < Min) {
        throw MinLimit{string};
    } else if(integer > Max) {
        throw MaxLimit{string};
    }
    return {static_cast<TableTypes::Column>(integer), result.getRest()};
}