#include "Quit.h"
#include "../../Application/Application.h"

Quit Quit:: instance;

ConstString Quit::actionString{"quit"};

Action* Quit::quit() noexcept {
    return &instance;
}

Action* Quit::action() {
    delete component;
    component = nullptr;
    Application::quit();
    return nullptr;
}