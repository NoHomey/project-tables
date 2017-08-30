#include "Count.h"
#include <cassert>

#include "../../Messages/CountedRows/CountedRows.h"

Count Count::instance;

ConstString Count::actionString{"Count"};

Count::Count() noexcept
: Base{CountState::ParseTableName} { }

Action* Count::controller() noexcept {
    return &instance;
}

Action* Count::parseTableName() {
    return Base::parseTableName<Count>(CountState::ParseColumnAndValue, CountState::TableNotFound);
}

Action* Count::parseColumnAndValue() {
    return Base::parseColumnAndValue(CountState::Count);
}

Action* Count::count() {
    const TableTypes::Column column = arguments[1].asColumn() - 1;
    TableTypes::Row countedRows = 0;
    Argument& argument = arguments[2];
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
    return showMessage(new CountedRows{countedRows});
}

Action* Count::action() {
    switch(getState()) {
        case CountState::ParseTableName: return parseTableName();
        case CountState::TableNotFound: return tableNotFound();
        case CountState::ParseColumnAndValue: return parseColumnAndValue();
        case CountState::Count: return count();
        default: assert(false);
    };
}

Action* Count::controlAction() noexcept {
    setState(CountState::ParseTableName);
    return this;
}