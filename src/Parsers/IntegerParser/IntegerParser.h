#pragma once

#include "../CharSequenceParser/CharSequenceParser.h"
#include "../Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"
#include "../../Table/TableTypes/TableTypes.h"

class IntegerParser {
public:
    class SingleSign: public Exception {
    public:
        SingleSign(char sign) noexcept;

        char getSign() const noexcept;

    private:
        char sign;
    };

    class InvalidInteger: public InvalidSymbolAtPosition {
    public:
        InvalidInteger(size_t position, char symbol, ConstString& token) noexcept;
    };

    class MaxLimit: public TokenException {
    public:
        MaxLimit(ConstString& token) noexcept;
    };

    class MinLimit: public TokenException {
    public:
        MinLimit(ConstString& token) noexcept;
    };

    class ParseResult: public ::ParseResult<TableTypes::Integer, TableTypes::Integer> {
    private:
        using Base = ::ParseResult<TableTypes::Integer, TableTypes::Integer>;

    public:
        ParseResult() noexcept;

        ParseResult(TableTypes::Integer integer, ConstString& rest) noexcept;
    };

public:
    static ParseResult parse(ConstString& string);

public:
    IntegerParser() = delete;

protected:
    struct Processed {
        const size_t offset;
        ConstString extracted;
        ConstString digitSequence;
        ConstString rest;
        const bool hasSign;
        const bool isNegative;
    };

protected:
    static bool isMinus(char symbol) noexcept;

    static bool isPlus(char symbol) noexcept;

    static bool isSign(char symbol) noexcept;

    static bool isDigit(char symbol) noexcept;

    static bool isZero(char symbol) noexcept;

    static ConstString skipLeadingZeros(ConstString& string) noexcept;

    static Processed commonProcess(ConstString& string);

    static void ensureOnlyDigits(ConstString& string, ConstString& token, size_t offset);

    static void ensureInLimits(bool isNegative, ConstString& digitSequence, ConstString& token);

    static unsigned char toDigit(char symbol) noexcept;

    static TableTypes::Integer parseInteger(bool isNegative, ConstString& digitSequence) noexcept;
};