#include "Rename.h"
#include "../ParseTableName/ParseTableName.h"
#include "../Error/Error.h"
#include "../Result/Result.h"

Rename Rename:: instance;

ConstString Rename::actionString{"Rename"};

Action* Rename::rename() noexcept {
    instance.state = ParseTableName;
    return &instance;
}

Action* Rename::parseTableName() {
    Action* parseAction = ParseTableName::parseTableName()->action();
    if(parseAction != nullptr) {
        return parseAction;
    }
    Table* table = allTables.getTableByName(arguments[0].asTemporaryString());
    if(table == nullptr) {
        state = TableNotFound;
    } else {
        setCurrentTable(table);
        state = ParseNewTableName;
    }
    return this;
}

Action* Rename::tableNotFound() {
    return Error::showError();
}

Action* Rename::parseNewTableName() {
    Action* parseAction = ParseTableName::parseTableName()->action();
    if(parseAction != nullptr) {
        return parseAction;
    }
    ConstString& newName = arguments[1].asTemporaryString();
    Table* table = allTables.getTableByName(newName);
    if(table != nullptr) {
        state = currentTable->getName() == newName ? WarnForNoRename : NewNameIsNotUnique;
    } else {
        state = RenameTable;
    }
    return this;
}

Action* Rename::renameTable() {
    ConstString& newName = arguments[1].asTemporaryString();
    currentTable->rename({newName.cString(), newName.length()});
    return Result::showResult();
}

Action* Rename::newNameIsNotUnique() {
    return Error::showError();
}

Action* Rename::warnForNoRename() {
    return Error::showError();
}

Action* Rename::action() {
    switch(state) {
        case ParseTableName: return parseTableName();
        case TableNotFound: return tableNotFound();
        case ParseNewTableName: return parseNewTableName();
        case NewNameIsNotUnique: return newNameIsNotUnique();
        case WarnForNoRename: return warnForNoRename();
        case RenameTable: return renameTable();
    }
    return nullptr;
}
