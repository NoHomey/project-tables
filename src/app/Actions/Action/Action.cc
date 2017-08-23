#include "Action.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"
#include "../../Messages/UnknownQueryCommand/UnknownQueryCommand.h"
#include "../../../Components/Info/InfoComponent/InfoComponent.h"

Tables Action::allTables;

Table* Action::currentTable = nullptr;

Component* Action::component = nullptr;

ImmutableString Action::command;

MoveDynamicArray<Argument> Action::arguments;

DynamicArray<Action::ActionCommand> Action::commands;

Action::ActionCommand::ActionCommand() noexcept
: command{}, action{nullptr} { }

Action::ActionCommand::ActionCommand(ConstString& command, Action* action) noexcept
: command{command}, action{action} { }

ConstString& Action::ActionCommand::getCommand() const noexcept {
    return command;
}

Action* Action::ActionCommand::getAction() noexcept {
    return action;
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
        delete Action::component;
    }
    Action::component = component;
    if(component != nullptr) {
        component->render();
    }
}

void Action::registerCommands(DynamicArray<ActionCommand>&& commands) noexcept {
    Action::commands = std::move(commands);
}

const DynamicArray<Action::ActionCommand>& Action::getCommands() noexcept {
    return commands;
}

Action* Action::showMessage(const InfoModel* model) noexcept {
    if(model == nullptr) {
        setComponent(nullptr);
    } else {
        setComponent(new InfoComponent(model));
    }
    return nullptr;
}

Action* Action::selectAction(ConstString& action) {
    const size_t commandsCount = commands.size();
    for(size_t index = 0; index < commandsCount; ++index) {
        ActionCommand& command = commands[index];
        if(command.getCommand() == action) {
            return command.getAction()->controlAction();
        }
    }
    return showMessage(new UnknownQueryCommand(action));
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
    currentTable = nullptr;
    Action::command = {};
}

Action* Action::controlAction() noexcept {
    return nullptr;
}