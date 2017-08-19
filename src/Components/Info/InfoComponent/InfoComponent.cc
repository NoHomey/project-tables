#include "InfoComponent.h"
#include "../../../Renderer/CenteredRenderer/CenteredRenderer.h"
#include "../../../TypesOutputer/TypesOutputer.h"

InfoComponent InfoComponent::component;

InfoComponent* InfoComponent::inject(const String& string) {
    component.text = {string.cString(), string.length()};
    return &component;
}

void InfoComponent::render() {
    if(CenteredRenderer::queryCentered(text.length(), 1).bordered().exec()) {
        CenteredRenderer::clear();
        TypesOutputer::output(CenteredRenderer::getRenderer(), text);
        return;
    }
    BasicRenderer::getRenderer().clearWindow();
}

void InfoComponent::onComponentUnmount() {
    text = {};
}