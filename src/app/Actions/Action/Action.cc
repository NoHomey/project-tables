#include "Action.h"
#include "../ShowTables/ShowTables.h"
#include "../Error/Error.h"
#include "../Describe/Describe.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"

Tables Action::allTables;

Table* Action::currentTable = nullptr;

Component* Action::component = nullptr;

ImmutableString Action::command;

MoveDynamicArray<Argument> Action::arguments;

void Action::__mock() {
    allTables.addTable({"AAA"});
    allTables.addTable({"Ivo"});
}

void Action::reRender() {
    if(component != nullptr) {
        component->render();
    }
}

void Action::setCurrentTable(Table* currentTable) noexcept {
    Action::currentTable = currentTable;
}

void Action::setComponent(Component* component) noexcept {
    if(Action::component != nullptr) {
        Action::component->onComponentUnmount();
    }
    Action::component = component;
    if(component) {
        component->render();
    }
}

Action* Action::selectAction(ConstString& action) {
    if(action == ShowTables::actionString) {
        return ShowTables::showTables();
    }
    if(action == Describe::actionString) {
        return Describe::describe();
    }
    return Error::showError();
}

void Action::nullArguments() noexcept {
    const size_t size = arguments.size();
    for(size_t index = 0; index < size; ++index) {
        arguments[index].null();
    }
    arguments.empty();
}

void Action::takeAction(ConstString& command) {
    CharSequenceParser::ParseResult result;
    try {
        result = CharSequenceParser::parseSeparatedByWhiteSpaces(command);
    } catch(const Exception& error) {
        return;
    }
    Action::command = result.getRest();
    if(arguments.capacity() == 0) {
        arguments.extend(Action::ArgumentsIntialCapacity);
    }
    Action* action = selectAction(result.getExtracted());
    while(action != nullptr) {
        action = action->action();
    }
    nullArguments();
}