#include "ParseTableName.h"
#include "../../../Parsers/TableNameParser/TableNameParser.h"
#include "../../Messages/MissingTableName/MissingTableName.h"
#include "../../Messages/InvalidTableName/InvalidTableName.h"
#include "../Message/Message.h"

ParseTableName ParseTableName::instance;

Action* ParseTableName::parseTableName(ConstString& commandName, unsigned char argument) noexcept {
    instance.commandName = commandName;
    instance.argument = argument;
    return &instance;
}

Action* ParseTableName::action() {
    CharSequenceParser::ParseResult result;
    try {
        result = TableNameParser::parse(command);
    } catch(const TableNameParser::InvalidTableName& error) {
        return Message::showMessage(InvalidTableName::inject(error.getToken()));
    } catch(const Exception& error) {
        return Message::showMessage(MissingTableName::inject(commandName, Message::mappedArgumentIndexNames[argument]));
    }
    Action::command = result.getRest();
    arguments.push(result.getExtracted());
    return nullptr;
}