#include "ListCommandsModelAdaptor.h"

ConstString ListCommandsModelAdaptor::titleText{"Commands:"};

ListCommandsModelAdaptor::ListCommandsModelAdaptor(const DynamicArray<Action::ActionCommand>& commands) noexcept
: ListModel{true}, commands{commands} { }

const String& ListCommandsModelAdaptor::title() const noexcept {
    return titleText;
}

const String& ListCommandsModelAdaptor::item(size_t index) const noexcept {
    return commands[index].getCommand();
}

size_t ListCommandsModelAdaptor::itemsCount() const noexcept {
    return commands.size();
}