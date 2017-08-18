#include "Action.h"
#include "../ShowTables/ShowTables.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"

Tables Action::allTables;

Table* Action::currentTable = nullptr;

Component* Action::component = nullptr;

ImmutableString Action::command;

ConstString Action::ShowTablesAction{"Showtables"};

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

Action* Action::selectAction(ConstString& action) {
    if(action == ShowTablesAction) {
        return ShowTables::showTables();
    }
    return nullptr;
}

void Action::takeAction(ConstString& command) {
    CharSequenceParser::ParseResult result = CharSequenceParser::parseSeparatedByWhiteSpaces(command);
    Action::command = result.rest;
    Action* action = selectAction(result.extracted);
    while(action != nullptr) {
        action = action->action();
    }
}