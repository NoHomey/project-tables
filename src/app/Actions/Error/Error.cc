#include "Error.h"
#include "../../../Components/Info/InfoComponent/InfoComponent.h"

Error Error::instance;

Action* Error::showError() noexcept {
    return &instance; 
}

Action* Error::action() {
    setComponent(InfoComponent::inject(ConstString{"Error!"}));
    return nullptr;
}