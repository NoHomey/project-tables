#pragma once

#include "../IntegerParser/IntegerParser.h"
#include "../Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"
#include "../../Table/TableTypes/TableTypes.h"

class ColumnNumberParser: public IntegerParser {
public:
    using IsNull = CharSequenceParser::Null;

    using MaxLimit = IntegerParser::MaxLimit;

    class IsZero: public Exception { };

    class HasSign: public TokenException {
    public:
        HasSign(ConstString& token) noexcept;
    };

    class InvalidColumnNumber: public InvalidSymbolAtPosition {
    public:
        InvalidColumnNumber(size_t position, char symbol, ConstString& token) noexcept;

        InvalidColumnNumber(const InvalidSymbolAtPosition& error) noexcept;
    };

    class ParseResult: public ::ParseResult<TableTypes::Column> {
    private:
        using Base = ::ParseResult<TableTypes::Column>;

    public:
        ParseResult() noexcept;

        ParseResult(TableTypes::Column columnNumber, ConstString& rest) noexcept;
    };

public:
    static const TableTypes::Column Max = 10000;

    static const TableTypes::Column Min = 1;

public:
    static ParseResult parse(ConstString& string);

public:
    ColumnNumberParser() = delete;
};