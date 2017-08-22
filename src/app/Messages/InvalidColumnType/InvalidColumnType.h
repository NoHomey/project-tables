#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class InvalidColumnType: public InfoModel {
public:
    InvalidColumnType(const String& argument);

    InvalidColumnType(const InvalidColumnType& other) = delete;

    InvalidColumnType(InvalidColumnType&& other) = delete;

    InvalidColumnType& operator=(const InvalidColumnType& other) = delete;

    InvalidColumnType& operator=(InvalidColumnType&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString argument;
};