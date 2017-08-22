#include "ListTablesModelAdaptor.h"

ConstString ListTablesModelAdaptor::titleText{"Tables"};

ListTablesModelAdaptor::ListTablesModelAdaptor(const Tables& tables) noexcept
: ListModel{true}, tables{tables.getTables()} { }

const String& ListTablesModelAdaptor::title() const noexcept {
    return titleText;
}

const String& ListTablesModelAdaptor::item(size_t index) const noexcept {
    return tables.getElement(index).getName();
}

size_t ListTablesModelAdaptor::itemsCount() const noexcept {
    return tables.size();
}