#pragma once

#include "../Table/Table.h"
#include "../Container/DynamicArray/DynamicArray.htd"

class Tables {
public:
    Tables() noexcept = default;

    Tables(const Tables& other) = delete;

    Tables(Tables&& other) = delete;

    Tables& operator=(const Tables& other) = delete;

    Tables& operator=(Tables&& other) = delete;

public:
    Table* getTableByName(const String& name) noexcept;

    const DynamicArray<Table>& getTables() const noexcept;

    void addTable(Table&& table);

private:
    DynamicArray<Table> tables;
};