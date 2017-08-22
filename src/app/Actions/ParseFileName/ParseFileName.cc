#include "ParseFileName.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"
#include "../../Messages/MissingFileName/MissingFileName.h"

ParseFileName ParseFileName::instance;

Action* ParseFileName::parseFileName(ConstString& commandName) noexcept {
    instance.commandName = commandName;
    return &instance;
}

Action* ParseFileName::action() {
    CharSequenceParser::ParseResult result;
    try {
        result = CharSequenceParser::parseSeparatedByWhiteSpaces(command);
    } catch(const Exception& error) {
        return showMessage(new MissingFileName(commandName, arguments.size()));
    }
    Action::command = result.getRest();
    arguments.push(result.getExtracted());
    return nullptr;
}