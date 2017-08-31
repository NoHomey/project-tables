#include "Update.h"

#include "../../Messages/UpdatedRows/UpdatedRows.h"

Update Update::instance;

ConstString Update::actionString{"Update"};

ConstString Update::description{"Command usage: 'Update <Table> <Search Column number> <Search Column value> <Target Column number> <Target Column value>'. Command description: sets value of column with number <Target Column number> to <Target Column value> of all rows in Table with name <Table> which have <Serch Column value> in column with number <Search Column Number>."};

Action* Update::controller() noexcept {
    return &instance;
}

Update::Update() noexcept
: Base{UpdateState::ParseTableName} { }

Action* Update::parseTableName() {
    return Base::parseTableName<Update>(UpdateState::ParseSearchColumnAndValue, UpdateState::TableNotFound);
}

Action* Update::parseSearchColumnAndValue() {
    return Base::parseColumnAndValue(UpdateState::ParseTargetColumnAndValue);
}

Action* Update::parseTargetColumnAndValue() {
    return Base::parseColumnAndValue(UpdateState::UpdateRows);
}

Action* Update::updateRows() {
    TableTypes::Column searchColumn = Action::arguments[1].asColumn() - 1;
    Argument& searchValue = Action::arguments[2];
    TableTypes::Column targetColumn = Action::arguments[3].asColumn() - 1;
    Argument& targetValue = Action::arguments[4];
    RowsFilterResult searchRows;
    switch(searchValue.getType()) {
        case Argument::ArgumentType::Integer:
            searchRows = currentTable->selectRowsMatching(searchColumn, searchValue.asInteger());
            break;
        case Argument::ArgumentType::FractionalNumber:
            searchRows = currentTable->selectRowsMatching(searchColumn, searchValue.asFractionalNumber());
            break;
        case Argument::ArgumentType::String:
            searchRows = currentTable->selectRowsMatching(searchColumn, searchValue.moveString());
            break;
        case Argument::ArgumentType::Null:
            searchRows = currentTable->selectRowsMatching(searchColumn, nullptr);
            break;
        default: assert(false);
    }
    const TableTypes::Row count = searchRows.count();
    switch(targetValue.getType()) {
        case Argument::ArgumentType::Integer:
            currentTable->updateRows(searchRows, targetColumn, targetValue.asInteger());
            break;
        case Argument::ArgumentType::FractionalNumber:
            currentTable->updateRows(searchRows, targetColumn, targetValue.asFractionalNumber());
            break;
        case Argument::ArgumentType::String:
            currentTable->updateRows(searchRows, targetColumn, targetValue.moveString());
            break;
        case Argument::ArgumentType::Null:
            currentTable->updateRows(searchRows, targetColumn, nullptr);
            break;
        default: assert(false);
    }
    return showMessage(new UpdatedRows{count});
}

Action* Update::action() {
    switch(getState()) {
        case UpdateState::ParseTableName: return parseTableName();
        case UpdateState::TableNotFound: return Base::tableNotFound();
        case UpdateState::ParseSearchColumnAndValue: return parseSearchColumnAndValue();
        case UpdateState::ParseTargetColumnAndValue: return parseTargetColumnAndValue();
        case UpdateState::UpdateRows: return updateRows();
        default: assert(false);
    };
}

Action* Update::controlAction() noexcept {
    setState(UpdateState::ParseTableName);
    return this;
}