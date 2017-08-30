#include "Print.h"
#include "../../../Components/TablePage/TablePageComponent/TablePageComponent.h"

Print Print::instance;

ConstString Print::actionString{"Print"};

Print::Print() noexcept
: Base{PrintState::ParseTableName} { }

Action* Print::controller() noexcept {
    return &instance;
}

Action* Print::parseTableName() {
    return Base::parseTableName<Print>(PrintState::PrintTable, PrintState::TableNotFound);
}

Action* Print::printTable() {
    setComponent(new TablePageComponent{*currentTable, currentTable->selectAllRows()});
    return nullptr;
}

Action* Print::action() {
    switch(getState()) {
        case PrintState::ParseTableName: return parseTableName();
        case PrintState::TableNotFound: return tableNotFound();
        case PrintState::PrintTable: return printTable();
        default: return nullptr;
    };
}

Action* Print::controlAction() noexcept {
    setState(PrintState::ParseTableName);
    return this;
}