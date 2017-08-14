#pragma once

#include "../../String/FixedSizeString/FixedSizeString.h"
#include "ColumnMetaData/ColumnMetaData.h"
#include "../../Container/DynamicArray/DynamicArray.htd"

class Table {
public:
    Table(FixedSizeString&& name);

public:
    const FixedSizeString& getName() const noexcept;

    const DynamicArray<ColumnMetaData>& getColumnsMetaData() const noexcept;

    void addColumn(const ColumnMetaData& metaData);

private:
    FixedSizeString name;

    DynamicArray<ColumnMetaData> columnsMetaData;
};