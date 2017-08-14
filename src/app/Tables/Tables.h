#pragma once

#include "../Table/Table.h"
#include "../../Container/DynamicArray/DynamicArray.htd"

class Tables {
public:
    static Tables& getAllTables() noexcept;

public:
    Tables(const Tables& other) = delete;

    Tables(Tables&& other) = delete;

    Tables& operator=(const Tables& other) = delete;

    Tables& operator=(Tables&& other) = delete;

public:
    Table* getTableByName(const String& name) const noexcept;

    const DynamicArray<Table*>& getTables() const noexcept;

    void addTable(Table* table);

private:
    Tables() noexcept = default;

private:
    static Tables instance;

private:
    DynamicArray<Table*> tables;
};