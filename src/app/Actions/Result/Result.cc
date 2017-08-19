#include "Result.h"
#include "../../../Components/Info/InfoComponent/InfoComponent.h"

Result Result::instance;

Action* Result::showResult() noexcept {
    return &instance; 
}

Action* Result::action() {
    setComponent(InfoComponent::inject(ConstString{"Result!"}));
    return nullptr;
}