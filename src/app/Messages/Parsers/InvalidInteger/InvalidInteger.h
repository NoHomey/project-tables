#pragma once

#include "../ParserMessage/ParserMessage.h"
#include "../../../../Parsers/IntegerParser/IntegerParser.h"

class InvalidInteger: public ParserMessage {
public:
    InvalidInteger(TableTypes::Column column, const IntegerParser::InvalidInteger& error);

    InvalidInteger(const InvalidInteger& other) = delete;

    InvalidInteger(InvalidInteger&& other) = delete;

    InvalidInteger& operator=(const InvalidInteger& other) = delete;

    InvalidInteger& operator=(InvalidInteger&& other) = delete;

public:
    void outputOwnText(CharOutputStream& outputStream) const final;

private:
    static size_t calculateTextLength(const IntegerParser::InvalidInteger& error) noexcept;

private:
    static ConstString textBeginning;

    static ConstString textInvalidInteger;
    
    static ConstString textAtPosition;

    static ConstString textEnding;

    static const size_t ownTextLength;

private:
    FixedSizeString invalidToken;

    size_t position;

    char invalidSymbol;
};