#include "Tables.h"

Tables Tables::instance;

Tables& Tables::getAllTables() noexcept {
    return instance;
}

Table* Tables::getTableByName(const String& name) const noexcept {
    const size_t tablesCount = tables.size();
    for(size_t index = 0; index < tablesCount; ++index) {
        if(tables[index]->getName() == name) {
            return tables[index];
        }
    }
    return nullptr;
}

const DynamicArray<Table*>& Tables::getTables() const noexcept {
    return tables;
}

void Tables::addTable(Table* table) {
    tables.pushOne(table);
}