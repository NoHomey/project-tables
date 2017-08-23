#pragma once

#include "../../String/ConstString/ConstString.h"
#include "../Exceptions/Exception.h"
#include "../ParseResult/ParseResult.htd"

class CharSequenceParser {
public:
    class ParseResult: public ::ParseResult<ImmutableString, ConstString&> {
    private:
        using Base = ::ParseResult<ImmutableString, ConstString&>;

    public:
        ParseResult() noexcept = default;

        ParseResult(ConstString& extracted, ConstString& rest) noexcept;
    };

    class EmptyString: public Exception { };

    class NoCharSequenceFound: public Exception { };

public:
    static bool isWhiteSpace(char symbol) noexcept;

    static ParseResult parseSeparatedByWhiteSpaces(ConstString& string);

public:
    CharSequenceParser() = delete;
};