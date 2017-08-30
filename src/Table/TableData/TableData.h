#pragma once

#include "../../Container/DynamicArray/DynamicArray.htd"
#include "../../SharedPtr/SharedPtr.htd"
#include "RowsFilterResult/RowsFilterResult.h"
#include "../TableTypes/TableTypes.h"

class TableData {
public:
    class ColumnsLimit { };

public:
    TableData() noexcept;

    ~TableData() noexcept = default;

    TableData(const TableData& other) = delete;

    TableData(TableData&& other) = default;

    TableData& operator=(const TableData& other) = delete;
    
    TableData& operator=(TableData&& other) = default;

public:
    TableTypes::Row rowsCount() const noexcept;

    TableTypes::Column columnsCount() const noexcept;

    void addColumn();

    void insert(std::nullptr_t);

    void insert(TableTypes::Integer&& value);

    void insert(TableTypes::FractionalNumber&& value);

    void insert(TableTypes::String&& value);

    const SharedPtr& operator()(TableTypes::Row row, TableTypes::Column column) const noexcept;

    const SharedPtr& get(TableTypes::Row row, TableTypes::Column column) const noexcept;

    RowsFilterResult selectAllRows() const noexcept;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, std::nullptr_t) const;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::Integer& value) const;

    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::FractionalNumber& value) const;    

    RowsFilterResult selectRowsMatching(TableTypes::Column column, const TableTypes::String& value) const;
    
    void updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, std::nullptr_t);
    
    void updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, TableTypes::Integer&& value);

    void updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, TableTypes::FractionalNumber&& value);
    
    void updateRows(const RowsFilterResult& filteredRows, TableTypes::Column column, TableTypes::String&& value);

    void deleteRows(const RowsFilterResult& filteredRows) noexcept;

public:
    static const TableTypes::Column columnsLimit = 10000;

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

    static void deleteFractionalNumber(SharedPtr& ptr) noexcept;

    static void deleteString(SharedPtr& ptr) noexcept;

    static size_t calculateOptimalExtending(TableTypes::Row rowsCount) noexcept;

private:
    TableTypes::Row calculateRowFor(size_t index) const noexcept;

    size_t calculateIndexFor(TableTypes::Row row, TableTypes::Column column) const noexcept;

private:
    static const SharedPtr NullValue;

    static const size_t initialCapacity = 32;

private:
    DynamicArray<SharedPtr> data;

    TableTypes::Column columns;
};