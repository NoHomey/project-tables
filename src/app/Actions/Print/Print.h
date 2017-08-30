#pragma once

#include "../ActionRequiringTable/ActionRequiringTable.htd"

enum class PrintState {
    ParseTableName,
    TableNotFound,
    PrintTable
};

class Print: public ActionRequiringTable<PrintState> {
private:
    using Base = ActionRequiringTable<PrintState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Print() noexcept;

private:
    Action* parseTableName();

    Action* printTable();

public:
    static ConstString actionString;

private:
    static Print instance;
};
