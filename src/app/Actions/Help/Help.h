#pragma once

#include "../Action/Action.h"

class Help: public Action {
public:
    static Action* help() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Help() noexcept = default;

public:
    static ConstString actionString;

private:
    static Help instance;
};