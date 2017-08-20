#pragma once

#include "../CharSequenceParser/CharSequenceParser.h"
#include "../Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"

class TableNameParser {
public:
    class InvalidTableName: public InvalidSymbolAtPosition {
    public:
        InvalidTableName(size_t position, char symbol, ConstString& token) noexcept;
    };

public:
    static CharSequenceParser::ParseResult parse(ConstString& string);

public:
    TableNameParser() = delete;

private:
    static bool isLowerCaseLetter(char symbol) noexcept;

    static bool isUpperCaseLetter(char symbol) noexcept;

    static bool isLetter(char symbol) noexcept;

    static bool isDigit(char symbol) noexcept;

    static bool isDash(char symbol) noexcept;

    static bool isUnderscore(char symbol) noexcept;

    static bool isDolarSign(char symbol) noexcept;

    static bool isHashSymbol(char symbol) noexcept;

    static bool isFirstValid(char symbol) noexcept;

    static bool isSubsequentValid(char symbol) noexcept;
};