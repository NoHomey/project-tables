#pragma once

#include "../Action/Action.h"

class CreateTable: public Action {
private:
    enum class State {
        ParseTableName,
        TableNameIsNotUnique,
        CreateNewTable
    };

public:
    static Action* controller() noexcept;

    Action* action() final;
    
    Action* controlAction() noexcept final;

private:
    CreateTable() noexcept;

private:
    Action* parseTableName();

    Action* tableNameIsNotUnique();

    Action* createNewTable();

public:
    static ConstString actionString;

    static ConstString description;

private:
    static CreateTable instance;

private:
    State state;
};
