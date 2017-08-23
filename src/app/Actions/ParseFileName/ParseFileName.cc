#include "ParseFileName.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"
#include "../../Messages/MissingFileName/MissingFileName.h"

ParseFileName::ParseFileName(ConstString& commandName) noexcept
: commandName{commandName} { }

Action* ParseFileName::action() {
    CharSequenceParser::ParseResult result;
    try {
        result = CharSequenceParser::parseSeparatedByWhiteSpaces(command);
    } catch(const Exception& error) {
        showMessage(new MissingFileName(commandName, arguments.size()));
        return this;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return nullptr;
}