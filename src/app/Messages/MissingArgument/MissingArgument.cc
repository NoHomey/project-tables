#include "MissingArgument.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString MissingArgument::textBeginning{"Parse Error: Query command '"};

ConstString MissingArgument::textExpects{"' expects "};
 
ConstString MissingArgument::textAs{" as "};

ConstString MissingArgument::textEnding{" argument. But none was found."};

const size_t MissingArgument::ownTextLength = textBeginning.length() + textExpects.length()
                                                    + textAs.length() + textEnding.length();

ConstString MissingArgument::mappedArgumentIndexNames[mappedArgumentIndexNamesCount] = {
    "first",
    "second",
    "third",
    "fourth",
    "fifth",
    "sixth"
};

size_t MissingArgument::calculateTextLength(ConstString& argumentDescription, ConstString& command, unsigned int argument) noexcept {
    return ownTextLength + command.length() + argumentDescription.length() + mappedArgumentIndexNames[argument].length();
}

MissingArgument::MissingArgument(ConstString& argumentDescription, ConstString& command, unsigned int argument) noexcept
: InfoModel{calculateTextLength(argumentDescription, command, argument), true},
argumentDescription{argumentDescription}, commandName{command},
argument{mappedArgumentIndexNames[argument]} { }

void MissingArgument::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, textBeginning);
    TypesOutputer::output(outputStream, commandName);
    TypesOutputer::output(outputStream, textExpects);
    TypesOutputer::output(outputStream, argumentDescription);
    TypesOutputer::output(outputStream, textAs);
    TypesOutputer::output(outputStream, argument);
    TypesOutputer::output(outputStream, textEnding);
}