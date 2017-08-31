#include "Delete.h"
#include <cassert>

#include "../../Messages/DeletedRows/DeletedRows.h"

Delete Delete::instance;

ConstString Delete::actionString{"Delete"};

ConstString Delete::description{"Command usage: 'Delete <Table> <Column number> <Column value>'. Command description: Deletes all rows from Table with name <Tbale> which have <Column value> as value in column with number <Column number>."};

Action* Delete::controller() noexcept {
    return &instance;
}

void Delete::finalAction(TableTypes::Column column, Argument& argument) {
    TableTypes::Row deletedRows = 0;
    switch(argument.getType()) {
        case Argument::ArgumentType::Integer:
            deletedRows = currentTable->deleteRowsMatching(column, argument.asInteger());
            break;
        case Argument::ArgumentType::FractionalNumber:
            deletedRows = currentTable->deleteRowsMatching(column, argument.asFractionalNumber());
            break;
        case Argument::ArgumentType::String:
            deletedRows = currentTable->deleteRowsMatching(column, argument.moveString());
            break;
        case Argument::ArgumentType::Null:
            deletedRows = currentTable->deleteRowsMatching(column, nullptr);
            break;
        default: assert(false);
    }
    showMessage(new DeletedRows{deletedRows});
}