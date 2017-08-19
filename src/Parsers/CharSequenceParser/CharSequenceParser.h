#pragma once

#include "../../String/ConstString/ConstString.h"
#include "../Exceptions/Exception.h"

class CharSequenceParser {
public:
    class ParseResult {
    public:
        ParseResult() noexcept = default;

        ParseResult(ConstString& extracted, ConstString& rest) noexcept;

    public: 
        ConstString& getExtracted() const noexcept;

        ConstString& getRest() const noexcept;

    private:
        ImmutableString extracted;

        ImmutableString rest;
    };

    class EmptyString: public Exception { };

    class NoCharSequenceFound: public Exception { };

public:
    static bool isWhiteSpace(char symbol) noexcept;

    static ParseResult parseSeparatedByWhiteSpaces(ConstString& string);

public:
    CharSequenceParser() = delete;
};