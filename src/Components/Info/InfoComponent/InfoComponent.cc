#include "InfoComponent.h"
#include "../../../Renderer/CenteredRenderer/CenteredRenderer.h"
#include "../../../TypesOutputer/TypesOutputer.h"

const InfoComponent::Ratio InfoComponent::ratios[ratiosCount] = {{2, 5}, {2, 3}, {4, 5}, {7, 8}, {10, 11}};

InfoComponent::InfoComponent(const InfoModel* model) noexcept
: ComponentWithModel<InfoModel>{model}, width{0}, height{0}, lastLineLength{0}, linesCount{0} { } 

Window::size InfoComponent::calculateRatio(Window::size size, unsigned short index) noexcept {
    const Ratio& ratio = ratios[index];
    return (size / ratio.denominator) * ratio.numerator;
}

bool InfoComponent::calculateSizes() noexcept {
    const size_t textLength = model->textLength();
    const Window::size windowWidth = Window::getWidth();
    const Window::size windowHeight = Window::getHeight();
    const bool isWidthBigger = windowWidth >= windowHeight;
    const Window::size biggerWindowSize = isWidthBigger ? windowWidth : windowHeight;
    const Window::size smallerWindowSize = !isWidthBigger ? windowWidth : windowHeight;
    Window::size& biggerSize = isWidthBigger ? width : height;
    Window::size& smallerSize = !isWidthBigger ? width : height;
    for(unsigned int smallerIndex = 0; smallerIndex < ratiosCount; ++smallerIndex) {
        smallerSize = calculateRatio(smallerWindowSize, smallerIndex);
        for(unsigned int biggerIndex = 0; biggerIndex < ratiosCount; ++biggerIndex) {
            biggerSize = calculateRatio(biggerWindowSize, biggerIndex);
            lastLineLength = textLength % width;
            linesCount = (textLength / width) + (lastLineLength > 0);
            if(linesCount <= height) {
                if(CenteredRenderer::queryCentered(width, height).bordered().padding(1, 2).atLeastMargin(1, 1).exec()) {
                    return true;
                }
            }
        }
    }
    lastLineLength = textLength % width;
    linesCount = (textLength / width) + (lastLineLength > 0);
    if(linesCount <= height) {
        if(CenteredRenderer::queryCentered(width, height).bordered().atLeastMargin(1, 1).exec()) {
            return true;
        }
    }
    return false;
}

void InfoComponent::fillEmpty(Window::size count) const {
    CenteredRenderer& renderer = CenteredRenderer::getRenderer();
    for(Window::size counter = 0; counter < count; ++counter) {
        renderer << ' ';
    }
}

void InfoComponent::endLastLine() const {
    if(lastLineLength > 0) {
        fillEmpty(width - lastLineLength);
    }
}

void InfoComponent::fillEmptyLine() const {
    fillEmpty(width);
}

void InfoComponent::fillEmpty() const {
    const Window::size emptyLines = height - linesCount;
    endLastLine();
    for(Window::size counter = 0; counter < emptyLines; ++counter) {
        fillEmptyLine();
    }
}

void InfoComponent::render() {
    if(calculateSizes()) {
        CenteredRenderer::clear();
        model->output(CenteredRenderer::getRenderer());
        fillEmpty();
        return;
    }
    BasicRenderer::getRenderer().clearWindow();
}