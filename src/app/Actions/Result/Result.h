#pragma once

#include "../Action/Action.h"

class Result: public Action {
public:
    static Action* showResult() noexcept;

    Action* action() final;

private:
    Result() noexcept = default;

private:
    static Result instance;
};