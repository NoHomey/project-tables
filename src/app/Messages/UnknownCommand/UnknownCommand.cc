#include "UnknownCommand.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString UnknownCommand::textBeginning{"Parse Error: '"};

ConstString UnknownCommand::textEnding{"' is uknown command."};

const size_t UnknownCommand::ownTextLength = textBeginning.length() + textEnding.length();

UnknownCommand::UnknownCommand(const String& command)
: InfoModel{ownTextLength + command.length(), true}, unknownCommand{FixedSizeString::fromString(command)} { }

void UnknownCommand::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, unknownCommand);
    TypesOutputer::output(outputStream, textEnding);
}