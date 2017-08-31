#include "Action.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"
#include "../../Messages/UnknownCommand/UnknownCommand.h"
#include "../../../Components/Info/InfoComponent/InfoComponent.h"

Tables Action::allTables;

Table* Action::currentTable = nullptr;

Component* Action::component = nullptr;

ImmutableString Action::command;

MoveDynamicArray<Argument> Action::arguments;

Action::Commands Action::commands;

Action::ActionCommand::ActionCommand() noexcept
: command{}, description{}, action{nullptr} { }

Action::ActionCommand::ActionCommand(ConstString& command, ConstString& description, Action* action) noexcept
: command{command}, description{description}, action{action} { }

ConstString& Action::ActionCommand::getCommand() const noexcept {
    return command;
}

ConstString& Action::ActionCommand::getDescription() const noexcept {
    return description;
}

Action* Action::ActionCommand::getAction() noexcept {
    return action;
}

void Action::reRender() {
    if(component != nullptr) {
        component->render();
    }
}

Action::Commands::Commands(size_t count)
: commands{count} { }

DynamicArray<Action::ActionCommand>& Action::Commands::getCommands() noexcept {
    return commands;
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

void Action::registerCommands(Commands&& commands) noexcept {
    Action::commands = std::move(commands);
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
    DynamicArray<ActionCommand>& registerdCommands = commands.getCommands();
    const size_t commandsCount = registerdCommands.size();
    for(size_t index = 0; index < commandsCount; ++index) {
        ActionCommand& command = registerdCommands[index];
        if(command.getCommand() == action) {
            return command.getAction()->controlAction();
        }
    }
    return showMessage(new UnknownCommand(action));
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
    Action* action = selectAction(result.getParsed());
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