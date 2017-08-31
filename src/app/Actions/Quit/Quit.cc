#include "Quit.h"
#include "../../Application/Application.h"

Quit Quit::instance;

ConstString Quit::actionString{"quit"};

ConstString Quit::description{"Command usage: 'quit'. Command description: it quits Project Tables."};

Action* Quit::controller() noexcept {
    return &instance;
}

Action* Quit::action() {
    delete component;
    component = nullptr;
    Application::quit();
    return nullptr;
}

Action* Quit::controlAction() noexcept {
    return this;
}