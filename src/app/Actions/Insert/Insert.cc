#include "Insert.h"
#include "../../Messages/WrongNumberOfColumns/WrongNumberOfColumns.h"
#include "../../Messages/InsertIntoTableWithNoColumns/InsertIntoTableWithNoColumns.h"
#include "../../Messages/InsertedIntoTable/InsertedIntoTable.h"
#include <cassert>

Insert Insert::instance;

ConstString Insert::actionString{"Insert"};

Insert::Insert() noexcept
: Base{InsertState::ParseTableName} { }

Action* Insert::controller() noexcept {
    return &instance;
}

const InfoModel* Insert::missingColumnValue(TableTypes::Column column) {
    return new WrongNumberOfColumns{*Action::currentTable, column - 1};
}

Action* Insert::parseTableName() {
    return Base::parseTableName<Insert>(InsertState::ParseValue, InsertState::TableNotFound);
}

Action* Insert::parseValue() {
    if(arguments.size() == (currentTable->columnsCount() + 1)) {
        setState(InsertState::Insert);
        return this;
    }
    return parseValueForColumn(arguments.size(), InsertState::ParseValue);
}

Action* Insert::insert() {
    if(arguments.size() == 1) {
        return showMessage(new InsertIntoTableWithNoColumns(currentTable->getName()));
    }
    const TableTypes::Column columnsCount = currentTable->columnsCount();
    for(TableTypes::Column column = 1; column <= columnsCount; ++column) {
        Argument& argument = arguments[column];
        switch(argument.getType()) {
            case Argument::ArgumentType::Integer:
                currentTable->insert(argument.asInteger());
                break;
            case Argument::ArgumentType::FractionalNumber:
                currentTable->insert(argument.asFractionalNumber());
                break;
            case Argument::ArgumentType::String:
                currentTable->insert(argument.moveString());
                break;
            case Argument::ArgumentType::Null:
                currentTable->insert(nullptr);
                break;
            default: assert(false);
        }
    }
    return showMessage(new InsertedIntoTable(currentTable->getName()));
}

Action* Insert::action() {
    switch(getState()) {
        case InsertState::ParseTableName: return parseTableName();
        case InsertState::TableNotFound: return tableNotFound();
        case InsertState::ParseValue: return parseValue();
        case InsertState::Insert: return insert();
        default: assert(false);
    };
}

Action* Insert::controlAction() noexcept {
    setState(InsertState::ParseTableName);
    return this;
}