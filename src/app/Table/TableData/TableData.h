#pragma once

#include "../../../Container/DynamicArray/DynamicArray.htd"
#include "../../../SharedPtr/SharedPtr.htd"
#include "RowsFilterResult/RowsFilterResult.h"
#include "../TableTypes.h"

class TableData {
public:
    TableData() noexcept;

    ~TableData() noexcept = default;

    TableData(const TableData& other) = delete;

    TableData(TableData&& other) = delete;

    TableData& operator=(const TableData& other) = delete;
    
    TableData& operator=(TableData&& other) = delete;

public:
    TableTypes::Row rowsCount() const noexcept;

    TableTypes::Column columnsCount() const noexcept;

    void addColumn();

    void insert(TableTypes::Integer&& value);

    void insert(TableTypes::String&& value);

    size_t calculateIndexFor(TableTypes::Row row, TableTypes::Column column) const noexcept;

    const SharedPtr& operator()(TableTypes::Row row, TableTypes::Column column) const noexcept;

    const SharedPtr& get(TableTypes::Row row, TableTypes::Column column) const noexcept;

    RowsFilterResult selectAllRows() const noexcept;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, std::nullptr_t) const;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, TableTypes::Integer value) const;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::String& value) const;
    
    void updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, std::nullptr_t);
    
    void updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, TableTypes::Integer&& value);
    
    void updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, TableTypes::String&& value);

private:
    struct FindFirstResult {
        SharedPtr& shared;
        size_t index;
    };

    template<typename Type>
    FindFirstResult findFirstInColumn(TableTypes::Column column, const Type& value) noexcept;

    template<typename Type>
    SharedPtr obtainSharedPtrForValueInColumn(TableTypes::Column column, Type&& value);

    template<typename Type>
    void insertValue(Type&& value);

    template<typename Type>
    RowsFilterResult selectRowsMatchingValueInColumn(TableTypes::Column column, const Type& value) const;

    template<typename Type>
    void updateRowsColumn(const RowsFilterResult& filteredRows, TableTypes::Column column, Type&& value);

private:
    template<typename Type>
    static SharedPtr::Deleter deleterFor() noexcept;

private:
    static void deleteInteger(SharedPtr& ptr) noexcept;

    static void deleteString(SharedPtr& ptr) noexcept;

private:
    TableTypes::Row calculateRowFor(size_t index) const noexcept;

private:
    static const SharedPtr NullValue;

private:
    DynamicArray<SharedPtr> data;

    TableTypes::Column columns;
};