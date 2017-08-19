#include "ListTablesModelAdaptor.h"

ListTablesModelAdaptor ListTablesModelAdaptor::modelAdaptor;

ConstString ListTablesModelAdaptor::titleText{"Tables"};

const ListTablesModelAdaptor* ListTablesModelAdaptor::adapt(const Tables& tables) noexcept {
    modelAdaptor.tables = &tables.getTables();
    return &modelAdaptor;
}

ListTablesModelAdaptor::ListTablesModelAdaptor() noexcept
: tables{nullptr} { }

const String& ListTablesModelAdaptor::title() const noexcept {
    return titleText;
}

const String& ListTablesModelAdaptor::item(size_t index) const noexcept {
    return tables->getElement(index).getName();
}

size_t ListTablesModelAdaptor::itemsCount() const noexcept {
    return tables->size();
}