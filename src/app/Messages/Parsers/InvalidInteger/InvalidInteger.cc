#include "InvalidInteger.h"
#include "../../../../TypesOutputer/TypesOutputer.h"
#include "../../../../Table/ColumnMetaData/ColumnMetaData.h"

ConstString InvalidInteger::textNumberType{"integer"};

InvalidInteger::InvalidInteger(TableTypes::Column column, const IntegerParser::InvalidInteger& error)
: InvalidNumber{ColumnMetaDataStrings::Integer, textNumberType, column, error} { }