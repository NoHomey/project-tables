#include "CreateTable.h"
#include "../../ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"
#include "../ParseTableName/ParseTableName.h"
#include "../../Messages/TableExists/TableExists.h"
#include "../../Messages/TableCreated/TableCreated.h"

CreateTable CreateTable:: instance;

ConstString CreateTable::actionString{"Create"};

CreateTable::CreateTable() noexcept
: state{ParseTableName} { }

Action* CreateTable::createTable() noexcept {
    instance.state = ParseTableName;
    return &instance;
}

Action* CreateTable::parseTableName() {
    Action* parseAction = ParseTableName::parseTableName(actionString)->action();
    if(parseAction != nullptr) {
        return parseAction;
    }
    Table* table = allTables.getTableByName(arguments[0].asTemporaryString());
    if(table != nullptr) {
        state = TableNameIsNotUnique;
    } else {
        state = CreateNewTable;
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
        case ParseTableName: return parseTableName();
        case TableNameIsNotUnique: return tableNameIsNotUnique();
        case CreateNewTable: return createNewTable();
    }
    return nullptr;
}
