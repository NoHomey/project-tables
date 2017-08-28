#pragma once

#include "../ActionRequiringTableValue/ActionRequiringTableValue.htd"

enum class InsertState {
    ParseTableName,
    TableNotFound,
    ParseValue,
    Insert
};

class Insert: public ActionRequiringTableValue<InsertState> {
private:
    using Base = ActionRequiringTableValue<InsertState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Insert() noexcept;

private:
    Action* parseTableName();

    Action* parseValue();
    
    Action* insert();

public:
    static ConstString actionString;

private:
    static Insert instance;
};
