#include "Help.h"
#include "../../../Components/List/ListComponent/ListComponent.h"
#include "../../ModelAdaptors/ListCommandsModelAdaptor/ListCommandsModelAdaptor.h"

Help Help::instance;

ConstString Help::actionString{"help"};

Action* Help::help() noexcept {
    return &instance; 
}

Action* Help::action() {
    setComponent(new ListComponent(new ListCommandsModelAdaptor(commands)));
    return nullptr;
}