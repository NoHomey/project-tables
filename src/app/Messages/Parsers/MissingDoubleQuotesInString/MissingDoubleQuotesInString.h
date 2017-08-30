#pragma once

#include "../ParserMessage/ParserMessage.h"

class MissingDoubleQuotesInString: public ParserMessage {
public:
    MissingDoubleQuotesInString(ConstString& missingPosition, TableTypes::Column column, ConstString& invlaidString);

    virtual ~MissingDoubleQuotesInString() noexcept = default;

    MissingDoubleQuotesInString(const MissingDoubleQuotesInString& other) = delete;

    MissingDoubleQuotesInString(MissingDoubleQuotesInString&& other) = delete;

    MissingDoubleQuotesInString& operator=(const MissingDoubleQuotesInString& other) = delete;

    MissingDoubleQuotesInString& operator=(MissingDoubleQuotesInString&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textMissingDoubleQuotes;

    static ConstString textMakeSure;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString invalidString;

    ConstString missingPosition;
};