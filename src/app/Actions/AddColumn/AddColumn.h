#pragma once

#include "../ActionRequiringTable/ActionRequiringTable.htd"


enum class AddColumnState {
    ParseTableName,
    TableNotFound,
    ParseColumnType,
    AddNewColumn
};

class AddColumn: public ActionRequiringTable<AddColumnState> {
private:
    using Base = ActionRequiringTable<AddColumnState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    AddColumn() noexcept;

private:
    Action* parseTableName();

    Action* parseColumnType();

    Action* missingColumnType();

    Action* columnTypeIsUnknown();

    Action* addNewColumn();

public:
    static ConstString actionString;

    static ConstString description;

private:
    static AddColumn instance;
};
