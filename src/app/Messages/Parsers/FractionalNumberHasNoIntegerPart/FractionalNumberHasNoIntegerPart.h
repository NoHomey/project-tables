#pragma once

#include "../FractionalNumberIsMissingPart/FractionalNumberIsMissingPart.h"

class FractionalNumberHasNoIntegerPart: public FractionalNumberIsMissingPart {
public:
    FractionalNumberHasNoIntegerPart(TableTypes::Column column, ConstString& invalidToken);

    FractionalNumberHasNoIntegerPart(const FractionalNumberHasNoIntegerPart& other) = delete;

    FractionalNumberHasNoIntegerPart(FractionalNumberHasNoIntegerPart&& other) = delete;

    FractionalNumberHasNoIntegerPart& operator=(const FractionalNumberHasNoIntegerPart& other) = delete;

    FractionalNumberHasNoIntegerPart& operator=(FractionalNumberHasNoIntegerPart&& other) = delete;

private:
    static ConstString textMissingPart;
};