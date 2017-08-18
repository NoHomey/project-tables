#pragma once

#include "../../../Tables/Tables.h"
#include "../../../Components/Component.h"

class Action {
public:
    static void reRender();

public:
    virtual Action* action() = 0;

    void setCurrentTable(Table* currentTable) noexcept;

    void setComponent(Component* component) noexcept;

protected:
    static Tables allTables;

    static Table* currentTable;

    static Component* component;
};
