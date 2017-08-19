#include "Describe.h"
#include "../../ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"
#include "../ParseTableName/ParseTableName.h"
#include "../Error/Error.h"

Describe Describe:: instance;

ConstString Describe::actionString{"Describe"};

Action* Describe::describe() noexcept {
    instance.state = ParseTableName;
    return &instance;
}

Action* Describe::parseTableName() {
    Action* parseAction = ParseTableName::parseTableName()->action();
    if(parseAction != nullptr) {
        return parseAction;
    }
    Table* table = allTables.getTableByName(arguments[0].asTemporaryString());
    if(table == nullptr) {
        state = TableNotFound;
    } else {
        setCurrentTable(table);
        state = DescribeTable;
    }
    return this;
}

Action* Describe::tableNotFound() {
    return Error::showError();
}

Action* Describe::describeTable() {
    setComponent(ListComponent::inject(ListTableModelAdaptor::adapt(currentTable)));
    return nullptr;
}

Action* Describe::action() {
    switch(state) {
        case ParseTableName: return parseTableName();
        case TableNotFound: return tableNotFound();
        case DescribeTable: return describeTable();
    }
    return nullptr;
}
