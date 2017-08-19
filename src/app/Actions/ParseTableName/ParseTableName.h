#pragma once

#include "../Action/Action.h"

class ParseTableName: public Action {
public:
    static Action* parseTableName() noexcept;

    Action* action() final;

private:
    ParseTableName() noexcept = default;

private:
    static ParseTableName instance;
};
