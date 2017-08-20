#include "Action.h"
#include "../ShowTables/ShowTables.h"
#include "../Describe/Describe.h"
#include "../Rename/Rename.h"
#include "../CreateTable/CreateTable.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"
#include "../../Messages/UnknownQueryCommand/UnknownQueryCommand.h"
#include "../Message/Message.h"

Tables Action::allTables;

Table* Action::currentTable = nullptr;

Component* Action::component = nullptr;

ImmutableString Action::command;

MoveDynamicArray<Argument> Action::arguments;

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
    if(component != nullptr) {
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
    if(action == Rename::actionString) {
        return Rename::rename();
    }
    if(action == CreateTable::actionString) {
        return CreateTable::createTable();
    }
    return Message::showMessage(UnknownQueryCommand::inject(action));
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