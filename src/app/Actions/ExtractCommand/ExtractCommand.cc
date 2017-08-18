#include "ExtractCommand.h"
#include "../ShowTables/ShowTables.h"
#include "../../../Parsers/CharSequenceParser/CharSequenceParser.h"

ExtractCommand ExtractCommand::instance;

ConstString ExtractCommand::ShowTablesCommand{"Showtables"};

Action* ExtractCommand::exec(ConstString& command) noexcept {
    instance.command = command;
    return &instance;
}

Action* ExtractCommand::action() {
    CharSequenceParser::ParseResult extracted = CharSequenceParser::parseSeparatedByWhiteSpaces(command);

    if(extracted.parsed == ShowTablesCommand) {
        return ShowTables::showTables();
    }

    command = extracted.substracted;

    return this;
}