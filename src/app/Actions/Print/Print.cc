#include "Print.h"
#include "../../../Components/TablePage/TablePageComponent/TablePageComponent.h"

Print Print::instance;

ConstString Print::actionString{"Print"};

Action* Print::controller() noexcept {
    return &instance;
}

void Print::finalAction() {
    setComponent(new TablePageComponent{*currentTable, currentTable->selectAllRows()});
}