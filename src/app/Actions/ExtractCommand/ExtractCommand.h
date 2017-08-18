#pragma once

#include "../Action/Action.h"
#include "../../../String/ConstString/ConstString.h"

class ExtractCommand: public Action {
public:
    static Action* exec(ConstString& command) noexcept;

    Action* action() final;

private:
    ExtractCommand() noexcept = default;

private:
    static ExtractCommand instance;

    static ConstString ShowTablesCommand;

private:
    ImmutableString command;
};