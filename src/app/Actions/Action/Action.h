#pragma once

#include "../../../Tables/Tables.h"
#include "../../../Components/Component.h"
#include "../../../String/ConstString/ConstString.h"

class Action {
public:
    static void reRender();

    static void takeAction(ConstString& command);

public:
    virtual Action* action() = 0;

    void setCurrentTable(Table* currentTable) noexcept;

    void setComponent(Component* component) noexcept;

protected:
    static Tables allTables;

    static Table* currentTable;

    static Component* component;

    static ImmutableString command;

private:
    static Action* selectAction(ConstString& action);

private:
    static ConstString ShowTablesAction;
};
