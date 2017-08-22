#pragma once

#include "../../../Components/List/ListModel/ListModel.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../Container/DynamicArray/DynamicArray.htd"
#include "../../Actions/Action/Action.h"

class ListCommandsModelAdaptor: public ListModel {
public:
    ListCommandsModelAdaptor(const DynamicArray<Action::ActionCommand>& commands) noexcept;

    ListCommandsModelAdaptor(const ListCommandsModelAdaptor& other) = delete;

    ListCommandsModelAdaptor(ListCommandsModelAdaptor&& other) = delete;
    
    ListCommandsModelAdaptor& operator=(const ListCommandsModelAdaptor& other) = delete;

    ListCommandsModelAdaptor& operator=(ListCommandsModelAdaptor& other) = delete;

public:
    const String& title() const noexcept;
    
    const String& item(size_t index) const noexcept;

    size_t itemsCount() const noexcept;

private:
    static ConstString titleText;

private:
    const DynamicArray<Action::ActionCommand>& commands;
};