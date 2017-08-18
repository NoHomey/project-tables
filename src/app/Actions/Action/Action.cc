#include "Action.h"

Tables Action::allTables;

Table* Action::currentTable = nullptr;

Component* Action::component = nullptr;

void Action::reRender() {
    if(component != nullptr) {
        component->render();
    }
}

void Action::setCurrentTable(Table* currentTable) noexcept {
    Action::currentTable = currentTable;
}

void Action::setComponent(Component* component) noexcept {
    Action::component = component;
    component->render();
}