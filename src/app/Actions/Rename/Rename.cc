#include "Rename.h"
#include "../ParseTableName/ParseTableName.h"
#include "../../Messages/SuccessfullyRenamedTable/SuccessfullyRenamedTable.h"
#include "../../Messages/NoRename/NoRename.h"
#include "../../Messages/NewNameIsNotUnique/NewNameIsNotUnique.h"
#include "../Message/Message.h"

Rename Rename:: instance;

ConstString Rename::actionString{"Rename"};

Rename::Rename() noexcept
: Base{RenameState::ParseTableName} { }

Action* Rename::rename() noexcept {
    instance.setState(RenameState::ParseTableName);
    return &instance;
}

Action* Rename::parseTableName() {
    return Base::parseTableName<Rename>(RenameState::ParseNewTableName, RenameState::TableNotFound);
}

Action* Rename::parseNewTableName() {
    Action* parseAction = ParseTableName::parseTableName(actionString, 1)->action();
    if(parseAction != nullptr) {
        return parseAction;
    }
    ConstString& newName = arguments[1].asTemporaryString();
    Table* table = allTables.getTableByName(newName);
    if(table != nullptr) {
        setState(currentTable->getName() == newName ? RenameState::WarnForNoRename : RenameState::NewNameIsNotUnique);
    } else {
        setState(RenameState::RenameTable);
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
    switch(getState()) {
        case RenameState::ParseTableName: return parseTableName();
        case RenameState::TableNotFound: return tableNotFound();
        case RenameState::ParseNewTableName: return parseNewTableName();
        case RenameState::NewNameIsNotUnique: return newNameIsNotUnique();
        case RenameState::WarnForNoRename: return warnForNoRename();
        case RenameState::RenameTable: return renameTable();
        default: return nullptr;
    }
}
