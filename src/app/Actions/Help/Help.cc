#include "Help.h"
#include "../../../Components/List/ListComponent/ListComponent.h"
#include "../../ModelAdaptors/ListCommandsModelAdaptor/ListCommandsModelAdaptor.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"
#include "../../Messages/UnknownCommand/UnknownCommand.h"
#include "../../../TypesOutputer/TypesOutputer.h"

Help Help::instance;

ConstString Help::actionString{"help"};

ConstString Help::description{"Command usage: 'help' or 'help <Command>'. If no command name is provided it lists all avalible commands. If invoked with command name it shows command usage and description for command <Command>."};

Help::Description::Description(ConstString& description) noexcept
: InfoModel{description.length(), true}, description{description} { }

void Help::Description::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, description);
}

Action* Help::controller() noexcept {
    return &instance; 
}

Action* Help::action() {
    CharSequenceParser::ParseResult result;
    try {
        result = CharSequenceParser::parseSeparatedByWhiteSpaces(command);
    } catch(const Exception& error) {
        setComponent(new ListComponent(new ListCommandsModelAdaptor(commands.getCommands())));
        return nullptr;
    }
    ConstString& action = result.getParsed();
    DynamicArray<ActionCommand>& registerdCommands = commands.getCommands();
    const size_t commandsCount = registerdCommands.size();
    for(size_t index = 0; index < commandsCount; ++index) {
        ActionCommand& command = registerdCommands[index];
        if(command.getCommand() == action) {
            return showMessage(new Description{command.getDescription()});
        }
    }
    return showMessage(new UnknownCommand(action));
}

Action* Help::controlAction() noexcept {
    return this;
}