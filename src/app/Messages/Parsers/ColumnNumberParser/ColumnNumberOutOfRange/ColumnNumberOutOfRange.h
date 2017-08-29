#pragma once

#include "../../../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../../../String/ConstString/ConstString.h"
#include "../../../../../String/FixedSizeString/FixedSizeString.h"

class ColumnNumberOutOfRange: public InfoModel {
public:
    ColumnNumberOutOfRange(ConstString& outOfRangeColumnNumber);

    ColumnNumberOutOfRange(const ColumnNumberOutOfRange& other) = delete;

    ColumnNumberOutOfRange(ColumnNumberOutOfRange& other) = delete;

    ColumnNumberOutOfRange& operator=(const ColumnNumberOutOfRange& other) = delete;

    ColumnNumberOutOfRange& operator=(ColumnNumberOutOfRange& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textColumnNumberOutOfRange;
    
    static ConstString textBetweenLimits;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString outOfRangeColumnNumber;
};