#pragma once

#include "../IntegerParser/IntegerParser.h"
#include "../Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"
#include "../../Table/TableTypes/TableTypes.h"

class FractionalNumberParser: public IntegerParser {
public:
    using SingleSign = IntegerParser::SingleSign;

    class DigitsCountLimit: public TokenException {
    public:
        DigitsCountLimit(ConstString& token) noexcept;
    };

    class SingleFloatingPoint: public Exception { };

    class FractionalNumberHasNoIntegerPart: public TokenException {
    public:
        FractionalNumberHasNoIntegerPart(ConstString& token) noexcept;
    };

    class FractionalNumberHasNoFractionalPart: public TokenException {
    public:
        FractionalNumberHasNoFractionalPart(ConstString& token) noexcept;
    };

    class InvalidFractionalNumber: public InvalidSymbolAtPosition {
    public:
        InvalidFractionalNumber(size_t position, char symbol, ConstString& token) noexcept;

        InvalidFractionalNumber(const InvalidSymbolAtPosition& other) noexcept;
    };

    class ParseResult: public ::ParseResult<TableTypes::FractionalNumber> {
    private:
        using Base = ::ParseResult<TableTypes::FractionalNumber>;

    public:
        ParseResult() noexcept;

        ParseResult(std::nullptr_t, ConstString& rest) noexcept;

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