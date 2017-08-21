#include "Describe.h"
#include "../../ModelAdaptors/ListTableModelAdaptor/ListTableModelAdaptor.h"
#include "../../../Components/List/ListComponent/ListComponent.h"

Describe Describe:: instance;

ConstString Describe::actionString{"Describe"};

Describe::Describe() noexcept
: Base{DescribeState::ParseTableName} { }

Action* Describe::describe() noexcept {
    instance.setState(DescribeState::ParseTableName);
    return &instance;
}

Action* Describe::parseTableName() {
    return Base::parseTableName<Describe>(DescribeState::DescribeTable, DescribeState::TableNotFound);
}

Action* Describe::describeTable() {
    setComponent(ListComponent::inject(ListTableModelAdaptor::adapt(currentTable)));
    return nullptr;
}

Action* Describe::action() {
    switch(getState()) {
        case DescribeState::ParseTableName: return parseTableName();
        case DescribeState::TableNotFound: return tableNotFound();
        case DescribeState::DescribeTable: return describeTable();
        default: return nullptr;
    };
}
