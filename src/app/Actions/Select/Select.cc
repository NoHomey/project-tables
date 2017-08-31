#include "Select.h"
#include <cassert>

#include "../../Messages/NoRowsSelected/NoRowsSelected.h"
#include "../../../Components/TablePage/TablePageComponent/TablePageComponent.h"

Select Select::instance;

ConstString Select::actionString{"Select"};

ConstString Select::description{"Command usage: 'Select' <Table> <Column number> <Column value>'. Command description: Selects and prints rows from Table with name <Table> which have value <Column value> in column with number <Column number>."};

Action* Select::controller() noexcept {
    return &instance;
}

void Select::finalAction(TableTypes::Column column, Argument& argument) {
    RowsFilterResult selectedRows;
    switch(argument.getType()) {
        case Argument::ArgumentType::Integer:
            selectedRows = currentTable->selectRowsMatching(column, argument.asInteger());
            break;
        case Argument::ArgumentType::FractionalNumber:
            selectedRows = currentTable->selectRowsMatching(column, argument.asFractionalNumber());
            break;
        case Argument::ArgumentType::String:
            selectedRows = currentTable->selectRowsMatching(column, argument.moveString());
            break;
        case Argument::ArgumentType::Null:
            selectedRows = currentTable->selectRowsMatching(column, nullptr);
            break;
        default: assert(false);
    }
    if(selectedRows.count() == 0) {
        showMessage(new NoRowsSelected{currentTable->getName()});
        return;
    }
    setComponent(new TablePageComponent{*currentTable, std::move(selectedRows)});
}