#include "MissingTableName.h"
#include "../../../String/ConstString/ConstString.h"
#include "../../../TypesOutputer/TypesOutputer.h"

MissingTableName MissingTableName::instance;

ConstString MissingTableName::textBeginning{"Query command '"};

ConstString MissingTableName::textExpects{"' expects table name identificator as "};

ConstString MissingTableName::textEnding{" argument. But none was found."};

const size_t MissingTableName::ownTextLength = textBeginning.length() + textExpects.length() + textEnding.length();

MissingTableName* MissingTableName::inject(ConstString& command, ConstString& argument) {
    instance.commandName = command;
    instance.argument = argument;
    return &instance;
}

size_t MissingTableName::textLength() const noexcept {
    return ownTextLength + commandName.length() + argument.length();
}

void MissingTableName::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, commandName);
    TypesOutputer::output(outputStream, textExpects);
    TypesOutputer::output(outputStream, argument);
    TypesOutputer::output(outputStream, textEnding);
}