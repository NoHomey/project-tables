#pragma once

#include "../ActionUsingTableNameColumnAndValue/ActionUsingTableNameColumnAndValue.htd"

class Count: public ActionUsingTableNameColumnAndValue<Count> {
private:
    friend ActionUsingTableNameColumnAndValue<Count>;

    using Base = ActionUsingTableNameColumnAndValue<Count>;

public:
    static Action* controller() noexcept;

private:
    Count() noexcept = default;

private:
    static void finalAction(TableTypes::Column column, Argument& argument);

public:
    static ConstString actionString;

    static ConstString description;

private:
    static Count instance;
};
