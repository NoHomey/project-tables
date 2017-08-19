#pragma once

#include "../Action/Action.h"

class Describe: public Action {
private:
    enum State {
        ParseTableName,
        TableNotFound,
        DescribeTable
    };

public:
    static Action* describe() noexcept;

    Action* action() final;

private:
    Describe() noexcept = default;

private:
    Action* parseTableName();

    Action* tableNotFound();

    Action* describeTable();

public:
    static ConstString actionString;

private:
    static Describe instance;

private:
    State state;
};
