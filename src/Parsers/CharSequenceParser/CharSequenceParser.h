#pragma once

#include "../../String/ConstString/ConstString.h"

class CharSequenceParser {
public:
    struct ParseResult {
        ConstString extracted;
        ConstString rest;
    };

public:
    static bool isWhiteSpace(char symbol) noexcept;

    static ParseResult parseSeparatedByWhiteSpaces(ConstString& string) noexcept;

public:
    CharSequenceParser() = delete;
};