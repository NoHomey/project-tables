#pragma once

#include "../../../Components/List/ListModel/ListModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Table/Table.h"

class ListTableModelAdaptor: public ListModel {
public:
    ListTableModelAdaptor(const Table* table) noexcept;

    ListTableModelAdaptor(const ListTableModelAdaptor& other) = delete;

    ListTableModelAdaptor(ListTableModelAdaptor&& other) = delete;
    
    ListTableModelAdaptor& operator=(const ListTableModelAdaptor& other) = delete;

    ListTableModelAdaptor& operator=(ListTableModelAdaptor& other) = delete;

public:
    const String& title() const noexcept;
    
    const String& item(size_t index) const noexcept;

    size_t itemsCount() const noexcept;

private:
    const FixedSizeString& tableName;

    const DynamicArray<ColumnMetaData>& columnsMetaData;
};