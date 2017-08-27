#include "ShowTables.h"
#include "../../ModelAdaptors/ListTablesModelAdaptor/ListTablesModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"

ShowTables ShowTables::instance;

ConstString ShowTables::actionString{"Showtables"};

Action* ShowTables::controller() noexcept {
    return &instance; 
}

Action* ShowTables::action() {
    setComponent(new ListComponent(new ListTablesModelAdaptor(allTables)));
    return nullptr;
}

Action* ShowTables::controlAction() noexcept {
    return this;
}