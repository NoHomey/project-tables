#pragma once

#include "../Action/Action.h"

class ShowTables: public Action {
public:
    static Action* showTables() noexcept;

    Action* action() final;

private:
    ShowTables() noexcept = default;

public:
    static ConstString actionString;

private:
    static ShowTables instance;
};