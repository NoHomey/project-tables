#pragma once

#include "../Action/Action.h"

class CreateTable: public Action {
private:
    enum State {
        ParseTableName,
        TableNameIsNotUnique,
        CreateNewTable
    };

public:
    static Action* createTable() noexcept;

    Action* action() final;

private:
    CreateTable() noexcept = default;

private:
    Action* parseTableName();

    Action* tableNameIsNotUnique();

    Action* createNewTable();

public:
    static ConstString actionString;

private:
    static CreateTable instance;

private:
    State state;
};
