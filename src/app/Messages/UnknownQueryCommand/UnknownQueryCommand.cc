#include "UnknownQueryCommand.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../TypesOutputer/TypesOutputer.h"

UnknownQueryCommand UnknownQueryCommand::instance;

ConstString UnknownQueryCommand::textBeginning{"Parse Error: '"};

ConstString UnknownQueryCommand::textEnding{"' is uknown query command."};

const size_t UnknownQueryCommand::ownTextLength = textBeginning.length() + textEnding.length();

UnknownQueryCommand* UnknownQueryCommand::inject(const String& command) {
    instance.unknownCommand = {command.cString(), command.length()};
    return &instance;
}

size_t UnknownQueryCommand::textLength() const noexcept {
    return ownTextLength + unknownCommand.length();
}

void UnknownQueryCommand::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, unknownCommand);
    TypesOutputer::output(outputStream, textEnding);
}

void UnknownQueryCommand::releaseResources() noexcept {
    unknownCommand = {};
}