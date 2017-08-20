#include "Describe.h"
#include "../../ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"
#include "../ParseTableName/ParseTableName.h"
#include "../../Messages/TableNotFound/TableNotFound.h"
#include "../Message/Message.h"

Describe Describe:: instance;

ConstString Describe::actionString{"Describe"};

Action* Describe::describe() noexcept {
    instance.state = ParseTableName;
    return &instance;
}

Action* Describe::parseTableName() {
    Action* parseAction = ParseTableName::parseTableName(actionString, 0)->action();
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
    return Message::showMessage(TableNotFound::inject(arguments[0].asTemporaryString()));
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
