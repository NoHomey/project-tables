#include "ListComponent.h"
#include "../../../Renderer/CenteredRenderer/CenteredRenderer.h"
#include "../../../TypesOutputer/TypesOutputer.h"

ListComponent::ListComponent(const ListModel* model) noexcept
: ComponentWithPolymorphicModel<ListModel>{model}, minWidth{0}, minHeight{0}, width{0}, leftPadding{0} {
    minHeight = model->itemsCount() + 2;
    calculateMinWidth();
}

void ListComponent::calculateMinWidth() noexcept {
    const size_t itemsCount = model->itemsCount();
    minWidth = model->title().length();
    size_t itemLength;
    for(size_t index = 0; index < itemsCount; ++index) {
        itemLength = model->item(index).length();
        if(itemLength > minWidth) {
            minWidth = itemLength;
        }
    }
}

void ListComponent::loopSymbol(Window::size count, char symbol) {
    CenteredRenderer& renderer = CenteredRenderer::getRenderer();
    for(Window::size i = 0; i < count; ++i) {
        renderer << symbol;
    }
}

void ListComponent::addPadding(Window::size padding) {
    loopSymbol(padding, ' ');
}

void ListComponent::addText(const String& text) {
    TypesOutputer::output(CenteredRenderer::getRenderer(), text);
}

void ListComponent::addLine(const String& text) {
    const size_t paddingAndTextLength = text.length() + leftPadding;
    addPadding(leftPadding);
    addText(text);
    if(paddingAndTextLength < width) {
        addPadding(width - paddingAndTextLength);
    }
}

void ListComponent::addTitle() {
    const String& title = model->title();
    const Window::size blankSpace = width - title.length();
    const Window::size leftPadding = blankSpace / 2;
    addPadding(leftPadding);
    addText(title);
    addPadding(leftPadding + (blankSpace % 2));
    loopSymbol(width, '-');
}

void ListComponent::addItems() {
    const size_t itemsCount = model->itemsCount();
    for(size_t index = 0; index < itemsCount; ++index) {
        addLine(model->item(index));
    }
}

void ListComponent::renderList(Window::size padding) {
    CenteredRenderer::clear();
    leftPadding = padding;
    width = minWidth + (2 * padding);
    addTitle();
    addItems();
}

void ListComponent::render() {
    Window::size padding = maxHorizontalPadding;
    while(true) {
        if(CenteredRenderer::queryCentered(minWidth + (2 * padding), minHeight).bordered().atLeastMargin(1, 1).exec()) {
            renderList(padding);
            return;
        }
        if(padding == 0) {
            break;
        }
        --padding;
    }
    BasicRenderer::getRenderer().clearWindow();
}