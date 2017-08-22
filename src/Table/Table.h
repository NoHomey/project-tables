#pragma once

#include "../String/FixedSizeString/FixedSizeString.h"
#include "ColumnMetaData/ColumnMetaData.h"
#include "../Container/DynamicArray/DynamicArray.htd"
#include "TableData/TableData.h"

class Table {
public:
    Table(FixedSizeString&& name);

    Table() = default;

    Table(const Table& other) = delete;
    
    Table(Table&& other) = default;
    
    Table& operator=(const Table& other) = delete;
        
    Table& operator=(Table&& other) = default;

public:
    const FixedSizeString& getName() const noexcept;

    const DynamicArray<ColumnMetaData>& getColumnsMetaData() const noexcept;

    void addColumn(const ColumnMetaData& metaData);

    FixedSizeString rename(FixedSizeString&& newName) noexcept;

    TableData& data() noexcept;

    const TableData& data() const noexcept;

private:
    FixedSizeString name;

    DynamicArray<ColumnMetaData> columnsMetaData;

    TableData tableData;
};