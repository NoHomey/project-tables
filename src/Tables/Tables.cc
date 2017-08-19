#include "Tables.h"

Table* Tables::getTableByName(const String& name) noexcept {
    const size_t tablesCount = tables.size();
    for(size_t index = 0; index < tablesCount; ++index) {
        if(tables[index].getName() == name) {
            return &tables[index];
        }
    }
    return nullptr;
}

const MoveDynamicArray<Table>& Tables::getTables() const noexcept {
    return tables;
}

void Tables::addTable(Table&& table) {
    tables.push(std::move(table));
}