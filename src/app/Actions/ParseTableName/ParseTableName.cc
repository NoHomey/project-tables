#include "ParseTableName.h"
#include "../../../Parsers/TableNameParser/TableNameParser.h"
#include "../../Messages/MissingTableName/MissingTableName.h"
#include "../../Messages/InvalidTableName/InvalidTableName.h"

ParseTableName::ParseTableName(ConstString& commandName) noexcept
: commandName{commandName} { }

Action* ParseTableName::action() {
    CharSequenceParser::ParseResult result;
    try {
        result = TableNameParser::parse(command);
    } catch(const TableNameParser::InvalidTableName& error) {
        showMessage(new InvalidTableName(error));
        return this;
    } catch(const Exception& error) {
        showMessage(new MissingTableName(commandName, arguments.size()));
        return this;
    }
    Action::command = result.getRest();
    arguments.push(result.getParsed());
    return nullptr;
}