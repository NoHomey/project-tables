#pragma once

#include "../ActionRequiringTable/ActionRequiringTable.htd"

enum class SaveState {
    ParseTableName,
    TableNotFound,
    ParseFileName,
    SaveTable
};

class Save: public ActionRequiringTable<SaveState> {
private:
    using Base = ActionRequiringTable<SaveState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Save() noexcept;

private:
    Action* parseTableName();

    Action* parseFileName();

    Action* saveTable();

public:
    static ConstString actionString;

private:
    static Save instance;
};
