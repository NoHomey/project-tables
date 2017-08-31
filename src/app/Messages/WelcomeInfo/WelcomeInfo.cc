#include "WelcomeInfo.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ConstString WelcomeInfo::text{"Welcome to Project Tables. For list of commands type 'help'. For specific command usage type 'help <Command>'. Enter 'quit' to exit."};

WelcomeInfo WelcomeInfo::instance;

WelcomeInfo::WelcomeInfo() noexcept
: InfoModel{text.length(), false} { }

WelcomeInfo* WelcomeInfo::welcomeInfo() {
    return &instance;
}

void WelcomeInfo::output(CharOutputStream& outputStream) const {
    TypesOutputer::output(outputStream, text);
}