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
    switch(columnsMetaData->getElement(index).getType()) {
        case ColumnMetaData::Integer: return ColumnMetaDataStrings::Integer;
        case ColumnMetaData::String: return ColumnMetaDataStrings::String;
        case ColumnMetaData::FractionalNumber: return ColumnMetaDataStrings::FractionalNumber;
        default: return ColumnMetaDataStrings::Unknown;
    }
}

size_t ListTableModelAdaptor::itemsCount() const noexcept {
    return columnsMetaData->size();
}