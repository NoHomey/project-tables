#include "UnknownQueryCommand.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString UnknownQueryCommand::textBeginning{"Parse Error: '"};

ConstString UnknownQueryCommand::textEnding{"' is uknown query command."};

const size_t UnknownQueryCommand::ownTextLength = textBeginning.length() + textEnding.length();

UnknownQueryCommand::UnknownQueryCommand(const String& command)
: InfoModel{ownTextLength + command.length(), true}, unknownCommand{FixedSizeString::fromString(command)} { }

void UnknownQueryCommand::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, unknownCommand);
    TypesOutputer::output(outputStream, textEnding);
}