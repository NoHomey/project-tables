#include "StringParser.h"
#include <utility>

StringParser::ParseResult::ParseResult(FixedSizeString&& parsed, ConstString& rest) noexcept
: parsed{std::move(parsed)}, rest{rest} { }

FixedSizeString StringParser::ParseResult::moveParsed() noexcept {
    return std::move(parsed);
}

ConstString& StringParser::ParseResult::getRest() const noexcept {
    return rest;
}

StringParser::MissingQuotesInTheBeginning::MissingQuotesInTheBeginning(ConstString& token) noexcept
: TokenException{token} { }

StringParser::MissingQuotesInTheEnd::MissingQuotesInTheEnd(ConstString& token) noexcept
: TokenException{token} { }

StringParser::UnEscapedBackslash::UnEscapedBackslash(size_t position, ConstString& token) noexcept
: InvalidSymbolAtPosition{position, '\\', token} { }

bool StringParser::isQuotes(char symbol) noexcept {
    return symbol == '"';
}

bool StringParser::isBackslash(char symbol) noexcept {
    return symbol == '\\';
}

CharSequenceParser::ParseResult StringParser::extractString(ConstString& string) {
    const size_t offset = skipWhiteSpaces(string);
    ConstString text = {string, offset};
    if(!isQuotes(string[offset])) {
        throw MissingQuotesInTheBeginning{parseSeparatedByWhiteSpaces(text).getParsed()};
    }
    const size_t textLength = text.length();
    size_t index = 1;
    char symbol;
    for(; index < textLength; ++index) {
        symbol = text[index];
        if(isQuotes(symbol)) {
            break;
        }
        if(isBackslash(symbol)) {
            ++index;
            symbol = text[index];
            if(!isBackslash(symbol) && !isQuotes(symbol)) {
                throw UnEscapedBackslash{index - 1, {text, 0, index}};
            }
        }
    }
    if(index == textLength) {
        throw MissingQuotesInTheEnd{{text, 0, index}};
    }
    return{{text, 1, index - 1}, {text, index + 1}};
}

size_t StringParser::countEscapingBackslashes(ConstString& string) noexcept {
    const size_t length = string.length();
    size_t count = 0;
    for(size_t index = 0; index < length; ++index) {
        if(isBackslash(string[index])) {
            ++count;
            ++index;
        }
    }
    return count;
}

StringParser::ParseResult StringParser::parse(ConstString& token) {
    CharSequenceParser::ParseResult extracted = extractString(token);
    ConstString string = extracted.getParsed();
    const size_t stringLength = string.length();
    FixedSizeString result{stringLength - countEscapingBackslashes(string)};
    for(size_t index = 0; index < stringLength; ++index) {
        if(isBackslash(string[index])) {
            ++index;
        }
        result << string[index];
    }
    return {std::move(result), extracted.getRest()};
}