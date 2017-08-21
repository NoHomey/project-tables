#include "ListOfCommands.h"
#include "../../ShowTables/ShowTables.h"
#include "../../Describe/Describe.h"
#include "../../Rename/Rename.h"
#include "../../CreateTable/CreateTable.h"
#include "../../AddColumn/AddColumn.h"

ListOfCommands ListOfCommands::instance;

ConstString ListOfCommands::titleText{"Commands:"};

const ListOfCommands* ListOfCommands::listCommands() noexcept {
    return &instance;
}


const String& ListOfCommands::title() const noexcept {
    return titleText;
}

const String& ListOfCommands::item(size_t index) const noexcept {
    switch(static_cast<Commands>(index)) {
        case Commands::ShowTables: return ShowTables::actionString;
        case Commands::Describe: return Describe::actionString;
        case Commands::Rename: return Rename::actionString;
        case Commands::Create: return CreateTable::actionString;
        case Commands::AddColumn: return AddColumn::actionString;
        default: return titleText;
    }
}

size_t ListOfCommands::itemsCount() const noexcept {
    return static_cast<size_t>(Commands::CommandsCount);
}