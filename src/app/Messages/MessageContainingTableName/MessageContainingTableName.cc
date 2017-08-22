#include "MessageContainingTableName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

template<typename TableNameType>
MessageContainingTableName<TableNameType>::MessageContainingTableName(const String& tableName, size_t textLength)
: InfoModel{textLength + tableName.length(), true}, tableName{TableNameType::fromString(tableName)} { }

template<typename TableNameType>
void MessageContainingTableName<TableNameType>::outputTableName(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, tableName);
}

template class MessageContainingTableName<FixedSizeString>;

template class MessageContainingTableName<ImmutableString>;