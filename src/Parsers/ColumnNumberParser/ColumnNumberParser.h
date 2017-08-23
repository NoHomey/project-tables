#pragma once

#include "../IntegerParser/IntegerParser.h"
#include "../Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"
#include "../../Table/TableTypes/TableTypes.h"

class ColumnNumberParser: public IntegerParser {
public:
    class SingleMinus: public Exception { };

    class SinglePlus: public Exception { };

    class MaxLimit: public TokenException {
    public:
        MaxLimit(ConstString& token) noexcept;
    };

    class MinLimit: public TokenException {
    public:
        MinLimit(ConstString& token) noexcept;
    };

    class ParseResult: public ::ParseResult<TableTypes::Column, TableTypes::Column> {
    private:
        using Base = ::ParseResult<TableTypes::Column, TableTypes::Column>;

    public:
        ParseResult() noexcept;

        ParseResult(TableTypes::Column columnNumber, ConstString& rest) noexcept;
    };

public:
    static ParseResult parse(ConstString& string);

public:
    ColumnNumberParser() = delete;

private:
    static const TableTypes::Column Max = 10000;

    static const TableTypes::Column Min = 1;
};