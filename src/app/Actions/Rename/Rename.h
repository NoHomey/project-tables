#pragma once

#include "../Action/Action.h"

class Rename: public Action {
private:
    enum State {
        ParseTableName,
        TableNotFound,
        ParseNewTableName,
        NewNameIsNotUnique,
        WarnForNoRename,
        RenameTable
    };

public:
    static Action* rename() noexcept;

    Action* action() final;

private:
    Rename() noexcept = default;

private:
    Action* parseTableName();

    Action* tableNotFound();

    Action* parseNewTableName();

    Action* newNameIsNotUnique();

    Action* warnForNoRename();

    Action* renameTable();

public:
    static ConstString actionString;

private:
    static Rename instance;

private:
    State state;
};
