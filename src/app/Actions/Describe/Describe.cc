#include "Describe.h"
#include "../../ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"

Describe Describe::instance;

ConstString Describe::actionString{"Describe"};

Action* Describe::controller() noexcept {
    return &instance;
}

void Describe::finalAction() {
    setComponent(new ListComponent(new ListTableModelAdaptor(currentTable)));
}
