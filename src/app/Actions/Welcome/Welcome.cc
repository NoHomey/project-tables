#include "Welcome.h"
#include "../../Messages/WelcomeInfo/WelcomeInfo.h"

Action* Welcome::action() {
    return nullptr;
}

void Welcome::showWelcome() {
    showMessage(WelcomeInfo::welcomeInfo());
}