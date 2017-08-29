#pragma once

#include "../../../../../Components/Info/InfoModel/InfoModel.h"
#include "../../../../../String/ConstString/ConstString.h"
#include "../../../../../String/FixedSizeString/FixedSizeString.h"
#include "../../../../../Parsers/ColumnNumberParser/ColumnNumberParser.h"

class InvalidColumnNumber: public InfoModel {
public:
    InvalidColumnNumber(const ColumnNumberParser::InvalidColumnNumber& error);

    InvalidColumnNumber(const InvalidColumnNumber& other) = delete;

    InvalidColumnNumber(InvalidColumnNumber&& other) = delete;

    InvalidColumnNumber& operator=(const InvalidColumnNumber& other) = delete;

    InvalidColumnNumber& operator=(InvalidColumnNumber&& other) = delete;

public:
    void output(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(const ColumnNumberParser::InvalidColumnNumber& error) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textInvalidSymbol;
    
    static ConstString textAtPosition;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString invalidToken;

    size_t position;

    char invalidSymbol;
};