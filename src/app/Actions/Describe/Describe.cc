#include "Describe.h"
#include "../../ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"

Describe Describe::instance;

ConstString Describe::actionString{"Describe"};

ConstString Describe::description{"Command usage: 'Describe <Table>'. Command description: Lists column types of all columns of Table with name <Table>."};

Action* Describe::controller() noexcept {
    return &instance;
}

void Describe::finalAction() {
    setComponent(new ListComponent(new ListTableModelAdaptor(currentTable)));
}
