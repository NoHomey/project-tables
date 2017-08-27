#pragma once

#include "../ActionRequiringTable/ActionRequiringTable.htd"

enum class DescribeState {
    ParseTableName,
    TableNotFound,
    DescribeTable
};

class Describe: public ActionRequiringTable<DescribeState> {
private:
    using Base = ActionRequiringTable<DescribeState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Describe() noexcept;

private:
    Action* parseTableName();

    Action* describeTable();

public:
    static ConstString actionString;

private:
    static Describe instance;
};
