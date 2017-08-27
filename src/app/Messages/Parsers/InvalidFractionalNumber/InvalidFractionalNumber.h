#pragma once

#include "../InvalidNumber/InvalidNumber.h"
#include "../../../../Parsers/FractionalNumberParser/FractionalNumberParser.h"

class InvalidFractionalNumber: public InvalidNumber {
public:
    InvalidFractionalNumber(TableTypes::Column column, const FractionalNumberParser::InvalidFractionalNumber& error);

    InvalidFractionalNumber(const InvalidFractionalNumber& other) = delete;

    InvalidFractionalNumber(InvalidFractionalNumber&& other) = delete;

    InvalidFractionalNumber& operator=(const InvalidFractionalNumber& other) = delete;

    InvalidFractionalNumber& operator=(InvalidFractionalNumber&& other) = delete;

private:
    static ConstString textNumberType;
};