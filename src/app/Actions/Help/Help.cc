#include "Help.h"
#include "../../../Components/List/ListComponent/ListComponent.h"
#include "../../ModelAdaptors/ListCommandsModelAdaptor/ListCommandsModelAdaptor.h"

Help Help::instance;

ConstString Help::actionString{"help"};

Action* Help::controller() noexcept {
    return &instance; 
}

Action* Help::action() {
    setComponent(new ListComponent(new ListCommandsModelAdaptor(commands.getCommands())));
    return nullptr;
}

Action* Help::controlAction() noexcept {
    return this;
}