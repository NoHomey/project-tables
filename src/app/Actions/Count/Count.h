#pragma once

#include "../ActionRequiringTableColumnAndValue/ActionRequiringTableColumnAndValue.htd"

enum class CountState {
    ParseTableName,
    TableNotFound,
    ParseColumnAndValue,
    Count
};

class Count: public ActionRequiringTableColumnAndValue<Count, CountState> {
private:
    using Base = ActionRequiringTableColumnAndValue<Count, CountState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

private:
    Count() noexcept;

private:
    Action* parseTableName();

    Action* parseColumnAndValue();
    
    Action* count();

public:
    static ConstString actionString;

private:
    static Count instance;
};
