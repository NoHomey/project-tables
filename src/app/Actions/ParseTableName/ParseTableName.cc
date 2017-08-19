#include "ParseTableName.h"
#include "../../../Parsers/TableNameParser/TableNameParser.h"
#include "../Error/Error.h"

ParseTableName ParseTableName::instance;

Action* ParseTableName::parseTableName() noexcept {
    return &instance;
}

Action* ParseTableName::action() {
    CharSequenceParser::ParseResult result;
    try {
        result = TableNameParser::parse(command);
    } catch(const Exception& error) {
        return Error::showError();
    }
    Action::command = result.getRest();
    arguments.push(result.getExtracted());

    return nullptr;
}