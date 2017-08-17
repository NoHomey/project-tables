#pragma once

#include "../String/FixedSizeString/FixedSizeString.h"
#include "ColumnMetaData/ColumnMetaData.h"
#include "../Container/DynamicArray/DynamicArray.htd"

class Table {
public:
    Table(FixedSizeString&& name);

    Table() = delete;

    Table(const Table& other) = delete;
    
    Table(Table&& other) = delete;
    
    Table& operator=(const Table& other) = delete;
        
    Table& operator=(Table&& other) = delete;

public:
    const FixedSizeString& getName() const noexcept;

    const DynamicArray<ColumnMetaData>& getColumnsMetaData() const noexcept;

    void addColumn(const ColumnMetaData& metaData);

    void rename(FixedSizeString&& newName) noexcept;

private:
    FixedSizeString name;

    DynamicArray<ColumnMetaData> columnsMetaData;
};