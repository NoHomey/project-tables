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

    TableTypes::Column columnsCount() const noexcept;

    void addColumn(const ColumnMetaData& metaData);

    FixedSizeString rename(FixedSizeString&& newName) noexcept;

    const TableData& data() const noexcept;

public:
    void insert(std::nullptr_t);
    
    void insert(TableTypes::Integer&& value);
    
    void insert(TableTypes::FractionalNumber&& value);
    
    void insert(TableTypes::String&& value);

    RowsFilterResult selectAllRows() const noexcept;
    
    RowsFilterResult selectRowsMatching(TableTypes::Column column, std::nullptr_t) const;
    
    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::Integer& value) const;
    
    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::FractionalNumber& value) const;    
    
    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::String& value) const;

    TableTypes::Row countRowsMatching(TableTypes::Column column, std::nullptr_t) const;

    TableTypes::Row countRowsMatching(TableTypes::Column column, const TableTypes::Integer& value) const;

    TableTypes::Row countRowsMatching(TableTypes::Column column, const TableTypes::FractionalNumber& value) const;

    TableTypes::Row countRowsMatching(TableTypes::Column column, const TableTypes::String& value) const;

private:
    FixedSizeString name;

    DynamicArray<ColumnMetaData> columnsMetaData;

    TableData tableData;
};