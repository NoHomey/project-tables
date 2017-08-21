#include "ListTableModelAdaptor.h"

ListTableModelAdaptor ListTableModelAdaptor::modelAdaptor;

const ListTableModelAdaptor* ListTableModelAdaptor::adapt(const Table* table) noexcept {
    modelAdaptor.tableName = &table->getName();
    modelAdaptor.columnsMetaData = &table->getColumnsMetaData();
    return &modelAdaptor;
}

ListTableModelAdaptor::ListTableModelAdaptor() noexcept
: tableName{nullptr}, columnsMetaData{nullptr} { }

const String& ListTableModelAdaptor::title() const noexcept {
    return *tableName;
}

const String& ListTableModelAdaptor::item(size_t index) const noexcept {
    return ColumnMetaData::columnTypeAsString(columnsMetaData->getElement(index).getType());
}

size_t ListTableModelAdaptor::itemsCount() const noexcept {
    return columnsMetaData->size();
}