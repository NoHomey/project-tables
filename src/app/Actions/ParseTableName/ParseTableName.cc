#include "ParseTableName.h"
#include "../../../Parsers/TableNameParser/TableNameParser.h"
#include "../../Messages/MissingTableName/MissingTableName.h"
#include "../../Messages/InvalidTableName/InvalidTableName.h"

Action* ParseTableName::action() {
    return nullptr;
}

bool ParseTableName::parseTableName(ConstString& commandName) {
    CharSequenceParser::ParseResult result;
    try {
        result = TableNameParser::parse(command);
    } catch(const TableNameParser::InvalidTableName& error) {
        showMessage(new InvalidTableName(error));
        return false;
    } catch(const Exception& error) {
        showMessage(new MissingTableName(commandName, arguments.size()));
        return false;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return true;
}