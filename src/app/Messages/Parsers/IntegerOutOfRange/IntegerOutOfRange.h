#pragma once

#include "../ParserMessage/ParserMessage.h"
#include "../../../../Parsers/IntegerParser/IntegerParser.h"

class IntegerOutOfRange: public ParserMessage {
public:
    IntegerOutOfRange(TableTypes::Column column, ConstString& outOfRangeInteger);

    IntegerOutOfRange(const IntegerOutOfRange& other) = delete;

    IntegerOutOfRange(IntegerOutOfRange&& other) = delete;

    IntegerOutOfRange& operator=(const IntegerOutOfRange& other) = delete;

    IntegerOutOfRange& operator=(IntegerOutOfRange&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textIntegerOutOfRange;
    
    static ConstString textBetweenLimits;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString outOfRangeInteger;
};