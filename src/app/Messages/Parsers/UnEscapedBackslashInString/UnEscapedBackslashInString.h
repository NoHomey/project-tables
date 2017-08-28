#pragma once

#include "../ParserMessage/ParserMessage.h"
#include "../../../../Parsers/StringParser/StringParser.h"

class UnEscapedBackslashInString: public ParserMessage {
public:
    UnEscapedBackslashInString(TableTypes::Column column, const StringParser::UnEscapedBackslash& error);

    UnEscapedBackslashInString(const UnEscapedBackslashInString& other) = delete;

    UnEscapedBackslashInString(UnEscapedBackslashInString&& other) = delete;

    UnEscapedBackslashInString& operator=(const UnEscapedBackslashInString& other) = delete;

    UnEscapedBackslashInString& operator=(UnEscapedBackslashInString&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(const StringParser::UnEscapedBackslash& error) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    size_t position;

    FixedSizeString invalidToken;
};