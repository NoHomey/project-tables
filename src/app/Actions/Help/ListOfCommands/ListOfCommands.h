#pragma once

#include "../../../../Components/List/ListModel/ListModel.h"
#include "../../../../String/ConstString/ConstString.h"

class ListOfCommands: public ListModel {
public:
    static const ListOfCommands* listCommands() noexcept;

public:
    const String& title() const noexcept;
    
    const String& item(size_t index) const noexcept;

    size_t itemsCount() const noexcept;
    
private:
    ListOfCommands() noexcept = default;

    ListOfCommands(const ListOfCommands& other) = delete;

    ListOfCommands(ListOfCommands&& other) = delete;
    
    ListOfCommands& operator=(const ListOfCommands& other) = delete;

    ListOfCommands& operator=(ListOfCommands& other) = delete;

private:
    static ListOfCommands instance;

    static ConstString titleText;

private:
    enum Commands {
        ShowTables,
        Describe,
        Rename,
        Create,
        CommandsCount
    };
};