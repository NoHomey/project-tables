#pragma once

#include "../ActionRequiringTable/ActionRequiringTable.htd"

enum class RenameState {
    ParseTableName,
    TableNotFound,
    ParseNewTableName,
    NewNameIsNotUnique,
    WarnForNoRename,
    RenameTable
};

class Rename: public ActionRequiringTable<RenameState> {
private:
    using Base = ActionRequiringTable<RenameState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Rename() noexcept;

private:
    Action* parseTableName();

    Action* parseNewTableName();

    Action* newNameIsNotUnique();

    Action* warnForNoRename();

    Action* renameTable();

public:
    static ConstString actionString;

private:
    static Rename instance;
};
