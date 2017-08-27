#pragma once

#include "../ParserMessage/ParserMessage.h"

class FractionalNumberIsMissingPart: public ParserMessage {
public:
    FractionalNumberIsMissingPart(ConstString& missingPart, TableTypes::Column column, ConstString& invalidToken);

    FractionalNumberIsMissingPart(const FractionalNumberIsMissingPart& other) = delete;

    FractionalNumberIsMissingPart(FractionalNumberIsMissingPart&& other) = delete;

    FractionalNumberIsMissingPart& operator=(const FractionalNumberIsMissingPart& other) = delete;

    FractionalNumberIsMissingPart& operator=(FractionalNumberIsMissingPart&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textInvalidFractionalNumber;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    ConstString missingPart;

    FixedSizeString invalidToken;
};