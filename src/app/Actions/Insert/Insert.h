#pragma once

#include "../ActionRequiringTableValue/ActionRequiringTableValue.htd"

enum class InsertState {
    ParseTableName,
    TableNotFound,
    ParseValue,
    Insert
};

class Insert: public ActionRequiringTableValue<Insert, InsertState> {
private:
    friend ActionRequiringTableValue<Insert, InsertState>;

    using Base = ActionRequiringTableValue<Insert, InsertState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Insert() noexcept;

private:
    static const InfoModel* missingColumnValue(TableTypes::Column column);

private:
    Action* parseTableName();

    Action* parseValue();
    
    Action* insert();

public:
    static ConstString actionString;

private:
    static Insert instance;
};
