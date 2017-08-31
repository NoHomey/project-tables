#include "Print.h"
#include "../../../Components/TablePage/TablePageComponent/TablePageComponent.h"
#include "../../Messages/TableHasNoColumnsNothingToBePrinted/TableHasNoColumnsNothingToBePrinted.h"
#include "../../Messages/TableHasNoRowsNothingToBePrinted/TableHasNoRowsNothingToBePrinted.h"

Print Print::instance;

ConstString Print::actionString{"Print"};

ConstString Print::description{"Command usage: 'Print <Table>'. Command description: Prints Table with name <Table>."};

Action* Print::controller() noexcept {
    return &instance;
}

void Print::finalAction() {
    if(currentTable->columnsCount() == 0) {
        showMessage(new TableHasNoColumnsNothingToBePrinted{currentTable->getName()});
        return;
    }
    if(currentTable->rowsCount() == 0) {
        showMessage(new TableHasNoRowsNothingToBePrinted{currentTable->getName()});
        return;
    }
    setComponent(new TablePageComponent{*currentTable, currentTable->selectAllRows()});
}