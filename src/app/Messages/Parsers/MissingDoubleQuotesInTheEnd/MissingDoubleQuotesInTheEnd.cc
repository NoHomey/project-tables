#include "MissingDoubleQuotesInTheEnd.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString MissingDoubleQuotesInTheEnd::textMissingPosition{"end"};

MissingDoubleQuotesInTheEnd::MissingDoubleQuotesInTheEnd(TableTypes::Column column, ConstString& invalidString)
: MissingDoubleQuotesInString{textMissingPosition, column, invalidString} { }