#pragma once

#include "../CharSequenceParser/CharSequenceParser.h"
#include "../Exceptions/TokenException/TokenException.h"
#include "../../Table/ColumnMetaData/ColumnMetaData.h"

class ColumnTypeParser {
public:
    class ParseResult: public ::ParseResult<ColumnMetaData::ColumnType, ColumnMetaData::ColumnType> {
    private:
        using Base = ::ParseResult<ColumnMetaData::ColumnType, ColumnMetaData::ColumnType>;

    public:
        ParseResult() noexcept;

        ParseResult(ColumnMetaData::ColumnType columnType, ConstString& rest) noexcept;
    };

    class InvalidColumnType: public TokenException {
    public:
        InvalidColumnType(ConstString& token) noexcept;
    };

public:
    static ParseResult parse(ConstString& string);

public:
    ColumnTypeParser() = delete;

};