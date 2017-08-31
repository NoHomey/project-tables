#pragma once

#include "../ActionUsingTableNameColumnAndValue/ActionUsingTableNameColumnAndValue.htd"

class Select: public ActionUsingTableNameColumnAndValue<Select> {
private:
    friend ActionUsingTableNameColumnAndValue<Select>;

    using Base = ActionUsingTableNameColumnAndValue<Select>;

public:
    static Action* controller() noexcept;

private:
    Select() noexcept = default;

private:
    static void finalAction(TableTypes::Column column, Argument& argument);

public:
    static ConstString actionString;

    static ConstString description;

private:
    static Select instance;
};
