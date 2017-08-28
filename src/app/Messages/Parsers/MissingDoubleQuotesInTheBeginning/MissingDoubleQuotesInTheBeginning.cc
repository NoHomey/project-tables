#include "MissingDoubleQuotesInTheBeginning.h"
#include "../../../../TypesOutputer/TypesOutputer.h"

ConstString MissingDoubleQuotesInTheBeginning::textMissingPosition{"beginning"};

MissingDoubleQuotesInTheBeginning::MissingDoubleQuotesInTheBeginning(TableTypes::Column column, ConstString& invalidString)
: MissingDoubleQuotesInString{textMissingPosition, column, invalidString} { }