#pragma once

#include "../FractionalNumberIsMissingPart/FractionalNumberIsMissingPart.h"

class FractionalNumberHasNoFractionalPart: public FractionalNumberIsMissingPart {
public:
    FractionalNumberHasNoFractionalPart(TableTypes::Column column, ConstString& invalidToken);

    FractionalNumberHasNoFractionalPart(const FractionalNumberHasNoFractionalPart& other) = delete;

    FractionalNumberHasNoFractionalPart(FractionalNumberHasNoFractionalPart&& other) = delete;

    FractionalNumberHasNoFractionalPart& operator=(const FractionalNumberHasNoFractionalPart& other) = delete;

    FractionalNumberHasNoFractionalPart& operator=(FractionalNumberHasNoFractionalPart&& other) = delete;

private:
    static ConstString textMissingPart;
};