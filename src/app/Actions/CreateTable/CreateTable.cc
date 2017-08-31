#include "CreateTable.h"
#include "../../ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"
#include "../ParseTableName/ParseTableName.h"
#include "../../Messages/TableExists/TableExists.h"
#include "../../Messages/TableCreated/TableCreated.h"

CreateTable CreateTable::instance;

ConstString CreateTable::actionString{"Create"};

ConstString CreateTable::description{"Command usage: 'Create <Table>'. Command description: Creates new Table with name <Table>."};

CreateTable::CreateTable() noexcept
: state{State::ParseTableName} { }

Action* CreateTable::controller() noexcept {
    return &instance;
}

Action* CreateTable::parseTableName() {
    if(!ParseTableName::parseTableName(actionString)) {
        return nullptr;
    }
    Table* table = allTables.getTableByName(arguments[0].asTemporaryString());
    if(table != nullptr) {
        state = State::TableNameIsNotUnique;
    } else {
        state = State::CreateNewTable;
    }
    return this;
}

Action* CreateTable::tableNameIsNotUnique() {
    Table* table = allTables.getTableByName(arguments[0].asTemporaryString());
    return showMessage(new TableExists(table->getName()));
}

Action* CreateTable::createNewTable() {
    ConstString tableName = arguments[0].asTemporaryString();
    allTables.addTable({FixedSizeString::fromString(tableName)});
    return showMessage(new TableCreated(allTables.getTableByName(tableName)->getName()));
}

Action* CreateTable::action() {
    switch(state) {
        case State::ParseTableName: return parseTableName();
        case State::TableNameIsNotUnique: return tableNameIsNotUnique();
        case State::CreateNewTable: return createNewTable();
    }
    return nullptr;
}

Action* CreateTable::controlAction() noexcept {
    state = State::ParseTableName;
    return this;
}