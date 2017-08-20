#include "Rename.h"
#include "../ParseTableName/ParseTableName.h"
#include "../../Messages/TableNotFound/TableNotFound.h"
#include "../../Messages/SuccessfullyRenamedTable/SuccessfullyRenamedTable.h"
#include "../../Messages/NoRename/NoRename.h"
#include "../../Messages/NewNameIsNotUnique/NewNameIsNotUnique.h"
#include "../Message/Message.h"

Rename Rename:: instance;

ConstString Rename::actionString{"Rename"};

Action* Rename::rename() noexcept {
    instance.state = ParseTableName;
    return &instance;
}

Action* Rename::parseTableName() {
    Action* parseAction = ParseTableName::parseTableName(actionString, 0)->action();
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
    return Message::showMessage(TableNotFound::inject(arguments[0].asTemporaryString()));
}

Action* Rename::parseNewTableName() {
    Action* parseAction = ParseTableName::parseTableName(actionString, 1)->action();
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
    FixedSizeString oldName = currentTable->rename({newName.cString(), newName.length()});
    return Message::showMessage(SuccessfullyRenamedTable::inject(std::move(oldName), currentTable->getName()));
}

Action* Rename::newNameIsNotUnique() {
    return Message::showMessage(NewNameIsNotUnique::inject(currentTable->getName(),
        allTables.getTableByName(arguments[1].asTemporaryString())->getName()
    ));
}

Action* Rename::warnForNoRename() {
    return Message::showMessage(NoRename::inject(currentTable->getName()));
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
