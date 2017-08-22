#include "MessageContainingTableName.h"
#include "../../../TypesOutputer/TypesOutputer.h"

template<typename TableNameType>
void MessageContainingTableName<TableNameType>::releaseResources() noexcept {
    tableName = {};
}

template<typename TableNameType>
void MessageContainingTableName<TableNameType>::setTableName(const String& name) {
    tableName = TableNameType::fromString(name);
}

template<typename TableNameType>
void MessageContainingTableName<TableNameType>::outputTableName(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, tableName);
}

template class MessageContainingTableName<FixedSizeString>;

template class MessageContainingTableName<ImmutableString>;