#pragma once

#include "../Action/Action.h"

class Error: public Action {
public:
    static Action* showError() noexcept;

    Action* action() final;

private:
    Error() noexcept = default;

private:
    static Error instance;
};