#include "ListTableModelAdaptor.h"

ListTableModelAdaptor ListTableModelAdaptor::modelAdaptor;

ConstString ListTableModelAdaptor::IntegerText{"Integer"};

ConstString ListTableModelAdaptor::FractionalNumberText{"FractionalNumber"};

ConstString ListTableModelAdaptor::StringText{"String"};

ConstString ListTableModelAdaptor::UnknownText{"Unknown"};

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
        case ColumnMetaData::Integer: return IntegerText;
        case ColumnMetaData::String: return StringText;
        case ColumnMetaData::FractionalNumber: return FractionalNumberText;
        default: return UnknownText;
    }
}

size_t ListTableModelAdaptor::itemsCount() const noexcept {
    return columnsMetaData->size();
}