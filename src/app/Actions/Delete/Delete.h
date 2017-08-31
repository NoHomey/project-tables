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
    static void finalAction(TableTypes::Column column, Argument& argument);

public:
    static ConstString actionString;

    static ConstString description;

private:
    static Delete instance;
};
