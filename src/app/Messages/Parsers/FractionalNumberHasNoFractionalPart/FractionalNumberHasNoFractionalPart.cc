#include "FractionalNumberHasNoFractionalPart.h"

ConstString FractionalNumberHasNoFractionalPart::textMissingPart{"fractional"};

FractionalNumberHasNoFractionalPart::FractionalNumberHasNoFractionalPart(TableTypes::Column column, ConstString& invalidToken)
: FractionalNumberIsMissingPart{textMissingPart, column, invalidToken} {}