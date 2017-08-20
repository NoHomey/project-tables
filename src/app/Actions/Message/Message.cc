#include "Message.h"

#include "../../../Components/Info/InfoComponent/InfoComponent.h"

Message Message::instance;

Action* Message::showMessage(InfoModel* message) noexcept {
    instance.message = message;
    return &instance;
}

Action* Message::action() {
    if(message != nullptr) {
        setComponent(InfoComponent::inject(message));
    }
    return nullptr;
}