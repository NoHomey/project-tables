#include "UnknownQueryCommand.h"
#include "../../../TypesOutputer/TypesOutputer.h"

UnknownQueryCommand UnknownQueryCommand::instance;

ConstString UnknownQueryCommand::textBeginning{"Parse Error: '"};

ConstString UnknownQueryCommand::textEnding{"' is uknown query command."};

const size_t UnknownQueryCommand::ownTextLength = textBeginning.length() + textEnding.length();

UnknownQueryCommand* UnknownQueryCommand::inject(const String& command) {
    instance.unknownCommand = FixedSizeString::fromString(command);
    instance.setTextLength(ownTextLength + command.length());
    return &instance;
}

void UnknownQueryCommand::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, unknownCommand);
    TypesOutputer::output(outputStream, textEnding);
}

void UnknownQueryCommand::releaseResources() noexcept {
    unknownCommand = {};
}