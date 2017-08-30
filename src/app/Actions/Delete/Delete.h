#pragma once

#include "../ActionUsingTableNameColumnAndValue/ActionUsingTableNameColumnAndValue.htd"

class Delete: public ActionUsingTableNameColumnAndValue<Delete> {
private:
    friend ActionUsingTableNameColumnAndValue<Delete>;

    using Base = ActionUsingTableNameColumnAndValue<Delete>;

public:
    static Action* controller() noexcept;

private:
    Delete() noexcept = default;

private:
    static Action* finalAction(TableTypes::Column column, Argument& argument);

public:
    static ConstString actionString;

private:
    static Delete instance;
};