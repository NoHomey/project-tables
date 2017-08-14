#include "ListTableModelAdaptor.h"

ListTableModelAdaptor ListTableModelAdaptor::modelAdaptor;

ConstString ListTableModelAdaptor::IntegerText{"Integer"};

ConstString ListTableModelAdaptor::StringText{"String"};

ConstString ListTableModelAdaptor::UnknownText{"Unknown"};

const ListTableModelAdaptor* ListTableModelAdaptor::adapt(const Table* table) noexcept {
    modelAdaptor.table = table;
    return &modelAdaptor;
}

ListTableModelAdaptor::ListTableModelAdaptor() noexcept
: table{nullptr} { }

const String& ListTableModelAdaptor::title() const noexcept {
    return table->getName();
}

const String& ListTableModelAdaptor::item(size_t index) const noexcept {
    const ColumnMetaData& metaData = table->getColumnsMetaData()[index];
    switch(metaData.getType()) {
        case ColumnMetaData::Integer: return IntegerText;
        case ColumnMetaData::String: return StringText;
        default: return UnknownText;
    }
}

size_t ListTableModelAdaptor::itemsCount() const noexcept {
    return table->getColumnsMetaData().size();
}