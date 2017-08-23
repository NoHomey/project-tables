#pragma once

#include "../Action/Action.h"

class Quit: public Action {
public:
    static Action* quit() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Quit() noexcept = default;

public:
    static ConstString actionString;

private:
    static Quit instance;
};
