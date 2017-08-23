#pragma once

#include "../IntegerParser/IntegerParser.h"
#include "../Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"
#include "../../Table/TableTypes/TableTypes.h"

class FractionalNumberParser: public IntegerParser {
public:
    class DigitsCountLimit: public TokenException {
    public:
        DigitsCountLimit(ConstString& token) noexcept;
    };

    class SingleFloatingPoint: public Exception { };

    class FractionaNumberHasNoIntegerPart: public TokenException {
    public:
        FractionaNumberHasNoIntegerPart(ConstString& token) noexcept;
    };

    class IncompleteFractionaNumber: public TokenException {
    public:
        IncompleteFractionaNumber(ConstString& token) noexcept;
    };

    class ParseResult: public ::ParseResult<TableTypes::FractionalNumber> {
    private:
        using Base = ::ParseResult<TableTypes::FractionalNumber>;

    public:
        ParseResult() noexcept;

        ParseResult(TableTypes::FractionalNumber fractionalNumber, ConstString& rest) noexcept;
    };

public:
    static ParseResult parse(ConstString& string);

public:
    FractionalNumberParser() = delete;

private:
    static bool isFloatingPoint(char symbol) noexcept;

    static size_t findFirstFloatingPointIndex(ConstString& string) noexcept;

    static TableTypes::FractionalNumber parseFractionalNumber(
        bool isNegative, ConstString& integerPart, ConstString& fractionalPart
    ) noexcept;
};