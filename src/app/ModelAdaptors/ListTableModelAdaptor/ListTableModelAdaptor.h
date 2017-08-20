#pragma once

#include "../../../Components/List/ListModel/ListModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Table/Table.h"

class ListTableModelAdaptor: public ListModel {
public:
    static const ListTableModelAdaptor* adapt(const Table* table) noexcept;

public:
    const String& title() const noexcept;
    
    const String& item(size_t index) const noexcept;

    size_t itemsCount() const noexcept;
    
private:
    ListTableModelAdaptor() noexcept;

    ListTableModelAdaptor(const ListTableModelAdaptor& other) = delete;

    ListTableModelAdaptor(ListTableModelAdaptor&& other) = delete;
    
    ListTableModelAdaptor& operator=(const ListTableModelAdaptor& other) = delete;

    ListTableModelAdaptor& operator=(ListTableModelAdaptor& other) = delete;

private:
    static ListTableModelAdaptor modelAdaptor;

private:
    const FixedSizeString* tableName;

    const DynamicArray<ColumnMetaData>* columnsMetaData;
};