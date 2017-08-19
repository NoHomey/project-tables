#pragma once

#include "../Table/Table.h"
#include "../Container/MoveDynamicArray/MoveDynamicArray.htd"

class Tables {
public:
    Tables() noexcept = default;

    Tables(const Tables& other) = delete;

    Tables(Tables&& other) = delete;

    Tables& operator=(const Tables& other) = delete;

    Tables& operator=(Tables&& other) = delete;

public:
    Table* getTableByName(const String& name) noexcept;

    const MoveDynamicArray<Table>& getTables() const noexcept;

    void addTable(Table&& table);

private:
    MoveDynamicArray<Table> tables;
};