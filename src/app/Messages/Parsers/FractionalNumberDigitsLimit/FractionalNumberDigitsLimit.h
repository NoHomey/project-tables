#pragma once

#include "../ParserMessage/ParserMessage.h"

class FractionalNumberDigitsLimit: public ParserMessage {
public:
    FractionalNumberDigitsLimit(TableTypes::Column column, ConstString& invlaidNumber);

    FractionalNumberDigitsLimit(const FractionalNumberDigitsLimit& other) = delete;

    FractionalNumberDigitsLimit(FractionalNumberDigitsLimit&& other) = delete;

    FractionalNumberDigitsLimit& operator=(const FractionalNumberDigitsLimit& other) = delete;

    FractionalNumberDigitsLimit& operator=(FractionalNumberDigitsLimit&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString invalidNumber;
};