#include "InvalidFractionalNumber.h"
#include "../../../../TypesOutputer/TypesOutputer.h"
#include "../../../../Table/ColumnMetaData/ColumnMetaData.h"

ConstString InvalidFractionalNumber::textNumberType{"decimal fractional"};

InvalidFractionalNumber::InvalidFractionalNumber(TableTypes::Column column, const FractionalNumberParser::InvalidFractionalNumber& error)
: InvalidNumber{ColumnMetaDataStrings::FractionalNumber, textNumberType, column, error} { }