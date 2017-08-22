#include "MissingArgument.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingArgument::textBeginning{"Parse Error: Query command '"};

ConstString MissingArgument::textExpects{"' expects "};
 
ConstString MissingArgument::textAs{" as "};

ConstString MissingArgument::textEnding{" argument. But none was found."};

const size_t MissingArgument::ownTextLength = textBeginning.length() + textExpects.length()
                                                    + textAs.length() + textEnding.length();

MissingArgument::MissingArgument(ConstString& argumentDescription) noexcept
: argumentDescription{argumentDescription}, commandName{}, argument{} { }

void MissingArgument::set(ConstString& command, ConstString& argument) noexcept {
    commandName = command;
    this->argument = argument;
    setTextLength(ownTextLength + argumentDescription.length() + command.length() + argument.length());
}

void MissingArgument::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, commandName);
    TypesOutputer::output(outputStream, textExpects);
    TypesOutputer::output(outputStream, argumentDescription);
    TypesOutputer::output(outputStream, textAs);
    TypesOutputer::output(outputStream, argument);
    TypesOutputer::output(outputStream, textEnding);
}

void MissingArgument::releaseResources() noexcept {
    commandName = {};
    argument = {};
}