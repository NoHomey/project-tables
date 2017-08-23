#pragma once

#include "../../String/ConstString/ConstString.h"
#include "../../String/FixedSizeString/FixedSizeString.h"
#include "../Exceptions/Exception.h"
#include "../Exceptions/InvalidSymbolAtPosition/InvalidSymbolAtPosition.h"
#include "../ParseResult/ParseResult.htd"
#include "../CharSequenceParser/CharSequenceParser.h"

class StringParser: public CharSequenceParser {
public:
    class ParseResult {
    public:
        ParseResult() noexcept = default;

        ParseResult(ParseResult&& other) noexcept = default;

        ParseResult& operator=(ParseResult&& other) noexcept = default;
    
        ParseResult(FixedSizeString&& parsed, ConstString& rest) noexcept;
    
    public: 
        FixedSizeString moveParsed() noexcept;
    
        ConstString& getRest() const noexcept;
    
    private:
        FixedSizeString parsed;
    
        ImmutableString rest;
    };

    class MissingQuotesInTheBeginng: public TokenException {
    public:
        MissingQuotesInTheBeginng(ConstString& token) noexcept;
    };

    class MissingQuotesInTheEnd: public TokenException {
    public:
        MissingQuotesInTheEnd(ConstString& token) noexcept;
    };

    class UnEscapedBackslash: public InvalidSymbolAtPosition {
    public:
        UnEscapedBackslash(size_t position, ConstString& token) noexcept;
    };

public:
    static ParseResult parse(ConstString& string);

public:
    StringParser() = delete;

private:
    static bool isQuotes(char symbol) noexcept;

    static bool isBackslash(char symbol) noexcept;

    static CharSequenceParser::ParseResult extractString(ConstString& string);

    static size_t countEscapingBackslashes(ConstString& string) noexcept;
};