#pragma once

#include "../Action/Action.h"

class ShowTables: public Action {
public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    ShowTables() noexcept = default;

public:
    static ConstString actionString;

    static ConstString description;

private:
    static ShowTables instance;
};