#include "ListTableModelAdaptor.h"

ListTableModelAdaptor::ListTableModelAdaptor(const Table* table) noexcept
: ListModel{true}, tableName{table->getName()}, columnsMetaData{table->getColumnsMetaData()} { }

const String& ListTableModelAdaptor::title() const noexcept {
    return tableName;
}

const String& ListTableModelAdaptor::item(size_t index) const noexcept {
    return ColumnMetaData::columnTypeAsString(columnsMetaData.getElement(index).getType());
}

size_t ListTableModelAdaptor::itemsCount() const noexcept {
    return columnsMetaData.size();
}