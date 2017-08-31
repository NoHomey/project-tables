#include "Count.h"
#include <cassert>

#include "../../Messages/CountedRows/CountedRows.h"

Count Count::instance;

ConstString Count::actionString{"Count"};

ConstString Count::description{"Command usage: 'Count' <Table> <Column number> <Column value>'. Command description: Counts the number of rows which have value <Column value> in column with number <Column number>."};

Action* Count::controller() noexcept {
    return &instance;
}

void Count::finalAction(TableTypes::Column column, Argument& argument) {
    TableTypes::Row countedRows = 0;
    switch(argument.getType()) {
        case Argument::ArgumentType::Integer:
            countedRows = currentTable->countRowsMatching(column, argument.asInteger());
            break;
        case Argument::ArgumentType::FractionalNumber:
            countedRows = currentTable->countRowsMatching(column, argument.asFractionalNumber());
            break;
        case Argument::ArgumentType::String:
            countedRows = currentTable->countRowsMatching(column, argument.moveString());
            break;
        case Argument::ArgumentType::Null:
            countedRows = currentTable->countRowsMatching(column, nullptr);
            break;
        default: assert(false);
    }
    showMessage(new CountedRows{countedRows});
}