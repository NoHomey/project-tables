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

    const SharedPtr& operator()(TableTypes::Row row, TableTypes::Column column) const noexcept;

    const SharedPtr& get(TableTypes::Row row, TableTypes::Column column) const noexcept;

    RowsFilterResult selectAllRows() const noexcept;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, std::nullptr_t) const noexcept;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, TableTypes::Integer value) const noexcept;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::String& value) const noexcept;

private:
    struct FindFirstResult {
        SharedPtr& shared;
        size_t index;
    };

    template<typename Type>
    FindFirstResult findFirstInColumn(TableTypes::Column column, const Type& value) noexcept;

    template<typename Type>
    SharedPtr obtainSharedPtrForValueInColumn(TableTypes::Column column, Type&& value, SharedPtr::Deleter deleter);

    template<typename Type>
    void insert(Type&& value, SharedPtr::Deleter deleter);

    template<typename Type>
    RowsFilterResult selectRowsMatchingValueInColumn(TableTypes::Column column, const Type& value) const noexcept;

private:
    static const SharedPtr NullValue;

    static void deleteInteger(SharedPtr& ptr) noexcept;

    static void deleteString(SharedPtr& ptr) noexcept;

private:
    TableTypes::Row calculateRowFor(size_t index) const noexcept;

private:
    DynamicArray<SharedPtr> data;

    TableTypes::Column columns;
};