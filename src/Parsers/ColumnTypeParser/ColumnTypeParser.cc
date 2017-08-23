#include "ColumnTypeParser.h"

ColumnTypeParser::ParseResult::ParseResult() noexcept
: Base{ColumnMetaData::ColumnType::Unknown} { }

ColumnTypeParser::ParseResult::ParseResult(ColumnMetaData::ColumnType columnType, ConstString& rest) noexcept
: Base{columnType, rest} { }

ColumnTypeParser::InvalidColumnType::InvalidColumnType(ConstString& token) noexcept
: TokenException{token} { }

ColumnTypeParser::ParseResult ColumnTypeParser::parse(ConstString& string) {
    CharSequenceParser::ParseResult result = CharSequenceParser::parseSeparatedByWhiteSpaces(string);
    ConstString& extracted = result.getParsed();
    ConstString& rest = result.getRest();
    if(extracted == ColumnMetaDataStrings::Integer) {
        return {ColumnMetaData::ColumnType::Integer, rest};
    }
    if(extracted == ColumnMetaDataStrings::FractionalNumber) {
        return {ColumnMetaData::ColumnType::FractionalNumber, rest};
    }
    if(extracted == ColumnMetaDataStrings::String) {
        return {ColumnMetaData::ColumnType::String, rest};
    }
    throw InvalidColumnType{extracted};
}