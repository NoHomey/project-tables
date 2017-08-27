#include "FractionalNumberHasNoIntegerPart.h"

ConstString FractionalNumberHasNoIntegerPart::textMissingPart{"integer"};

FractionalNumberHasNoIntegerPart::FractionalNumberHasNoIntegerPart(TableTypes::Column column, ConstString& invalidToken)
: FractionalNumberIsMissingPart{textMissingPart, column, invalidToken} {}