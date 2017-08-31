#include "AddColumn.h"
#include "../../../Parsers/ColumnTypeParser/ColumnTypeParser.h"
#include "../../Messages/MissingColumnType/MissingColumnType.h"
#include "../../Messages/InvalidColumnType/InvalidColumnType.h"
#include "../../Messages/ColumnsLimitReached/ColumnsLimitReached.h"
#include "../../Messages/NewColumnAdded/NewColumnAdded.h"

AddColumn AddColumn::instance;

ConstString AddColumn::actionString{"AddColumn"};

AddColumn::AddColumn() noexcept
: Base{AddColumnState::ParseTableName} { }

Action* AddColumn::controller() noexcept {
    return &instance;
}

Action* AddColumn::parseTableName() {
    return Base::parseTableName<AddColumn>(AddColumnState::ParseColumnType, AddColumnState::TableNotFound);
}

Action* AddColumn::parseColumnType() {
    ColumnTypeParser::ParseResult result;
    try {
        result = ColumnTypeParser::parse(command);
    } catch(const ColumnTypeParser::InvalidColumnType& error) {
        return showMessage(new InvalidColumnType{error.getToken()});
    } catch(const Exception& error) {
        return showMessage(MissingColumnType::missingColumnType());
    }
    Action::command = result.getRest();
    arguments.push(static_cast<TableTypes::Integer>(result.getParsed()));
    setState(AddColumnState::AddNewColumn);
    return this;
}

Action* AddColumn::addNewColumn() {
    const ColumnMetaData::ColumnType columnType
        = static_cast<ColumnMetaData::ColumnType>(arguments[1].asInteger());
    try {
        currentTable->addColumn({columnType});
    } catch(const TableData::ColumnsLimit& error) {
        return showMessage(ColumnsLimitReached::columnsLimitReached());
    }
    return showMessage(new NewColumnAdded{currentTable->getName(), columnType});
}

Action* AddColumn::action() {
    switch(getState()) {
        case AddColumnState::ParseTableName: return parseTableName();
        case AddColumnState::TableNotFound: return tableNotFound();
        case AddColumnState::ParseColumnType: return parseColumnType();
        case AddColumnState::AddNewColumn: return addNewColumn();
        default: return nullptr;
    }
}

Action* AddColumn::controlAction() noexcept {
    setState(AddColumnState::ParseTableName);
    return this;
}