#pragma once

#include "../ActionRequiringTable/ActionRequiringTable.htd"

enum class InsertState {
    ParseTableName,
    TableNotFound,
    RemoveTableNameFromArguments,
    ParseValue,
    MissingValue,
    Insert
};

class Insert: public ActionRequiringTable<InsertState> {
private:
    using Base = ActionRequiringTable<InsertState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Insert() noexcept;

private:
    Action* parseTableName();

    Action* removeTableNameFromArguments();

    Action* parseInteger();

    Action* parseFractionalNumber();

    Action* parseString();

    Action* parseValue();

    Action* missingValue();
    
    Action* insert();

public:
    static ConstString actionString;

private:
    static Insert instance;
};
