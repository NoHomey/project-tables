#pragma once

#include "../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class InvalidColumnType: public InfoModel {
public:
    static InvalidColumnType* inject(const String& argument);

public:
    void output(CharOutputStream& outputStream) const final;
    
    void releaseResources() noexcept final;

private:
    InvalidColumnType() noexcept = default;

    InvalidColumnType(const InvalidColumnType& other) = delete;

    InvalidColumnType(InvalidColumnType&& other) = delete;

    InvalidColumnType& operator=(const InvalidColumnType& other) = delete;

    InvalidColumnType& operator=(InvalidColumnType&& other) = delete;

private:
    static InvalidColumnType instance;

    static ConstString textBeginning;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString argument;
};