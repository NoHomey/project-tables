#include "Insert.h"
#include "../../Application/Application.h"

Insert Insert:: instance;

ConstString Insert::actionString{"Insert"};

Action* Insert::controller() noexcept {
    return &instance;
}

Action* Insert::action() {
    return nullptr;
}

Action* Insert::controlAction() noexcept {
    return this;
}