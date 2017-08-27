#pragma once

#include "../Action/Action.h"

class Insert: public Action {
public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Insert() noexcept = default;

public:
    static ConstString actionString;

private:
    static Insert instance;
};
