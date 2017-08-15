#pragma once

#include "../../../Container/DynamicArray/DynamicArray.htd"
#include "../../../SharedPtr/SharedPtr.htd"
#include "../../../String/FixedSizeString/FixedSizeString.h"

class TableData {
public:
    using Dimention = unsigned int;

    using Column = Dimention;

    using Row = Dimention;

    using Integer = unsigned long;

public:
    TableData() noexcept;

    ~TableData() noexcept = default;

    TableData(const TableData& other) = delete;

    TableData(TableData&& other) = delete;

    TableData& operator=(const TableData& other) = delete;
    
    TableData& operator=(TableData&& other) = delete;

public:
    Row rowsCount() const noexcept;

    Column columnsCount() const noexcept;

    void addColumn();

    void insert(Integer&& value);

    void insert(FixedSizeString&& value);

    const SharedPtr& operator()(Row row, Column column) const noexcept;

    const SharedPtr& get(Row row, Column column) const noexcept;

private:
    template<typename Type>
    SharedPtr& findFirstInColumn(Column column, const Type& value) noexcept;

    template<typename Type>
    void insert(Type&& value, SharedPtr::Deleter deleter);

private:
    static const SharedPtr NullValue;

    static void deleteInteger(SharedPtr& ptr) noexcept;

    static void deleteFixedSizeString(SharedPtr& ptr) noexcept;

private:
    DynamicArray<SharedPtr> data;

    Column columns;
};