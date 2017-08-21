#include "ColumnTypeParser.h"

ColumnTypeParser::ParseResult::ParseResult(ColumnMetaData::ColumnType columnType, ConstString& rest) noexcept
: type{columnType}, rest{rest} { }

ColumnTypeParser::ParseResult::ParseResult() noexcept
: type{ColumnMetaData::ColumnType::Unknown}, rest{} { }

ColumnMetaData::ColumnType ColumnTypeParser::ParseResult::getColumnType() const noexcept {
    return type;
}

ConstString& ColumnTypeParser::ParseResult::getRest() const noexcept {
    return rest;
}

ColumnTypeParser::InvalidColumnType::InvalidColumnType(ConstString& token) noexcept
: TokenException{token} { }

ColumnTypeParser::ParseResult ColumnTypeParser::parse(ConstString& string) {
    CharSequenceParser::ParseResult result = CharSequenceParser::parseSeparatedByWhiteSpaces(string);
    ConstString& extracted = result.getExtracted();
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