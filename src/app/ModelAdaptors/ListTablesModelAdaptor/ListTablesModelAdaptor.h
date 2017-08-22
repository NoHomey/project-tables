#pragma once

#include "../../../Components/List/ListModel/ListModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Tables/Tables.h"

class ListTablesModelAdaptor: public ListModel {
public:
    ListTablesModelAdaptor(const Tables& tables) noexcept;

    ListTablesModelAdaptor(const ListTablesModelAdaptor& other) = delete;

    ListTablesModelAdaptor(ListTablesModelAdaptor&& other) = delete;
    
    ListTablesModelAdaptor& operator=(const ListTablesModelAdaptor& other) = delete;

    ListTablesModelAdaptor& operator=(ListTablesModelAdaptor& other) = delete;

public:
    const String& title() const noexcept;
    
    const String& item(size_t index) const noexcept;

    size_t itemsCount() const noexcept;

private:
    static ConstString titleText;
    
private:
    const MoveDynamicArray<Table>& tables;
};