#pragma once

#include "../../../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../../../String/ConstString/ConstString.h"
#include "../../../../../String/FixedSizeString/FixedSizeString.h"

class ColumnNumberCannotHaveSign: public InfoModel {
public:
    ColumnNumberCannotHaveSign(ConstString& invalid) noexcept;

    ColumnNumberCannotHaveSign(const ColumnNumberCannotHaveSign& other) = delete;

    ColumnNumberCannotHaveSign(ColumnNumberCannotHaveSign&& other) = delete;

    ColumnNumberCannotHaveSign& operator=(const ColumnNumberCannotHaveSign& other) = delete;

    ColumnNumberCannotHaveSign& operator=(ColumnNumberCannotHaveSign&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textInValue;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString invalid;
};