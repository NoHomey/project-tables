#pragma once

#include "../../../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../../../String/ConstString/ConstString.h"

class ColumnNumberCannotBe: public InfoModel {
protected:
    ColumnNumberCannotBe(ConstString& invalidToken) noexcept;

    ColumnNumberCannotBe(const ColumnNumberCannotBe& other) = delete;

    ColumnNumberCannotBe(ColumnNumberCannotBe&& other) = delete;

    ColumnNumberCannotBe& operator=(const ColumnNumberCannotBe& other) = delete;

    ColumnNumberCannotBe& operator=(ColumnNumberCannotBe&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textCannotBe;

    static ConstString textEnding;
    
    static const size_t ownTextLength;

private:
    ConstString invalidToken;
};