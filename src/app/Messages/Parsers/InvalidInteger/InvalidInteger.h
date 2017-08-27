#pragma once

#include "../InvalidNumber/InvalidNumber.h"
#include "../../../../Parsers/IntegerParser/IntegerParser.h"

class InvalidInteger: public InvalidNumber {
public:
    InvalidInteger(TableTypes::Column column, const IntegerParser::InvalidInteger& error);

    InvalidInteger(const InvalidInteger& other) = delete;

    InvalidInteger(InvalidInteger&& other) = delete;

    InvalidInteger& operator=(const InvalidInteger& other) = delete;

    InvalidInteger& operator=(InvalidInteger&& other) = delete;

private:
    static ConstString textNumberType;
};