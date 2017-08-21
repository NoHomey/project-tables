#include "Help.h"
#include "ListOfCommands/ListOfCommands.h"
#include "../../../Components/List/ListComponent/ListComponent.h"

Help Help::instance;

ConstString Help::actionString{"help"};

Action* Help::help() noexcept {
    return &instance; 
}

Action* Help::action() {
    setComponent(ListComponent::inject(ListOfCommands::listCommands()));
    return nullptr;
}