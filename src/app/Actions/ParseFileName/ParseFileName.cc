#include "ParseFileName.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"
#include "../../Messages/MissingFileName/MissingFileName.h"

Action* ParseFileName::action() {
    return nullptr;
}

bool ParseFileName::parseFileName(ConstString& commandName) {
    CharSequenceParser::ParseResult result;
    try {
        result = CharSequenceParser::parseSeparatedByWhiteSpaces(command);
    } catch(const Exception& error) {
        showMessage(new MissingFileName(commandName, arguments.size()));
        return false;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return true;
}