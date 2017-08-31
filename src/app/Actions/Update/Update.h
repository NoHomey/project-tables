#pragma once

#include "../ActionRequiringTableColumnAndValue/ActionRequiringTableColumnAndValue.htd"

enum class UpdateState {
    ParseTableName,
    TableNotFound,
    ParseSearchColumnAndValue,
    ParseTargetColumnAndValue,
    UpdateRows
};

class Update: public ActionRequiringTableColumnAndValue<Update, UpdateState> {
private:
    using Base = ActionRequiringTableColumnAndValue<Update, UpdateState>;

public:
    static Action* controller() noexcept;

    Action* action() final;

    Action* controlAction() noexcept final;

protected:
    Update() noexcept;

private:
    Action* parseTableName();

    Action* parseSearchColumnAndValue();

    Action* parseTargetColumnAndValue();

    static Action* updateRows();

public:
    static ConstString actionString;

    static ConstString description;

private:
    static Update instance;
};