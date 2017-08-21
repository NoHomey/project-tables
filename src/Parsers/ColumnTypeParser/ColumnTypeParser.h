#pragma once

#include "../CharSequenceParser/CharSequenceParser.h"
#include "../Exceptions/TokenException/TokenException.h"
#include "../../Table/ColumnMetaData/ColumnMetaData.h"

class ColumnTypeParser {
public:
    class ParseResult {
    public:
        ParseResult() noexcept;

        ParseResult(ColumnMetaData::ColumnType columnType, ConstString& rest) noexcept;

    public:
        ColumnMetaData::ColumnType getColumnType() const noexcept;

        ConstString& getRest() const noexcept;

    private:
        ColumnMetaData::ColumnType type;

        ImmutableString rest;
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