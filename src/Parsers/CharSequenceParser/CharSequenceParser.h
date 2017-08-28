#pragma once

#include "../../String/ConstString/ConstString.h"
#include "../Exceptions/Exception.h"
#include "../Exceptions/TokenException/TokenException.h"
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

    class Null: public TokenException {
    public:
        Null(ConstString& rest) noexcept;
    };

public:
    static ParseResult parseSeparatedByWhiteSpaces(ConstString& string, bool throwNull = false);

public:
    CharSequenceParser() = delete;

protected:
    static bool isWhiteSpace(char symbol) noexcept;
    
    static bool isEndOfLine(char symbol) noexcept;

    static bool isDelimiter(char symbol) noexcept;

    static size_t skipWhiteSpaces(ConstString& string);
};