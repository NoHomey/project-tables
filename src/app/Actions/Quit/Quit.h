#pragma once

#include "../Action/Action.h"

class Quit: public Action {
public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Quit() noexcept = default;

public:
    static ConstString actionString;

    static ConstString description;

private:
    static Quit instance;
};
