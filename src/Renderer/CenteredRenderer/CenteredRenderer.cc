#include "CenteredRenderer.h"

CenteredRenderer CenteredRenderer::renderer;

CenteredRenderer& CenteredRenderer::getRenderer() noexcept {
    return renderer;
}

Centered& CenteredRenderer::queryCentered(Window::size width, Window::size height) noexcept {
    return renderer.centered.reset(width, height);
}

CenteredRenderer::CenteredRenderer() noexcept
: widthCounter{0}, heightCounter{0}, centered{} { }

bool CenteredRenderer::isVerticalMarginOdd() noexcept {
    return (Window::getHeight() - renderer.centered.totalHeight()) % 2;
}

size_t CenteredRenderer::calculatedRequiredBufferCapacity() const noexcept {
    return centered.totalHeight() * (centered.calculateLeftMargin() + centered.totalWidth()) 
        + (2 * centered.calculateTopMargin() + isVerticalMarginOdd());
}

void CenteredRenderer::loopSymbol(Window::size count, char symbol) {
    BasicRenderer& basicRenderer = BasicRenderer::getRenderer();
    for(Window::size i = 0; i < count; ++i) {
        basicRenderer << symbol;
    }
}

void CenteredRenderer::addTopMargin() {
    loopSymbol(renderer.centered.calculateTopMargin(), '\n');
}

void CenteredRenderer::addBottomMargin() {
    addTopMargin();
    if(isVerticalMarginOdd()) {
        addSymbol('\n');
    }
}

void CenteredRenderer::addLeftMargin() {
    loopSymbol(renderer.centered.calculateLeftMargin(), ' ');
}

void CenteredRenderer::addSymbol(char symbol) {
    BasicRenderer::getRenderer() << symbol;
}

void CenteredRenderer::addHorizontalBorder(char symbol) {
    addLeftMargin();
    loopSymbol(renderer.centered.totalWidth() - 1, symbol);
    addSymbol('\n');
}

void CenteredRenderer::addTopBorder() {
    if(renderer.centered.isBordered()) {
        addHorizontalBorder('_');
    }
}

void CenteredRenderer::addLeftBorder() {
    if(renderer.centered.isBordered()) {
        addSymbol('|');
    }
}

void CenteredRenderer::addRightBorder() {
    addLeftBorder();
}

void CenteredRenderer::addRightMargin() {
    addSymbol('\n');
}

void CenteredRenderer::addBottomBorder() {
    if(renderer.centered.isBordered()) {
        addHorizontalBorder('-');
    }
}

void CenteredRenderer::addTopPadding() {
    const Window::size topPadding = renderer.centered.getTopPadding();
    for(Window::size counter = 0; counter < topPadding; ++counter) {
        addLeftMargin();
        addLeftBorder();
        addLeftPadding();
        loopSymbol(renderer.centered.getWidth(), ' ');
        addRightPadding();
        addRightBorder();
        addRightMargin();
    }
}

void CenteredRenderer::addBottomPadding() {
    addTopPadding();
}
    
void CenteredRenderer::addLeftPadding() {
    const Window::size leftPadding = renderer.centered.getLeftPadding();
    if(leftPadding > 0) {
        loopSymbol(leftPadding, ' ');
    }
}
    
void CenteredRenderer::addRightPadding() {
    addLeftPadding();
}

void CenteredRenderer::clear() {
    BasicRenderer& basicRenderer = BasicRenderer::getRenderer();
    basicRenderer.ensureCapacity(renderer.calculatedRequiredBufferCapacity());
    basicRenderer.clear();
    addTopMargin();
    addTopBorder();
    addTopPadding();
    renderer.widthCounter = 0;
    renderer.heightCounter = 0;
}

void CenteredRenderer::widthReached() {
    widthCounter = 0;
    addRightPadding();
    addRightBorder();
    addRightMargin();
    ++heightCounter;
    if(heightCounter == centered.getHeight()) {
        addBottomPadding();
        addBottomBorder();
        addBottomMargin();
        BasicRenderer::getRenderer().render();
    }
}

CharOutputStream& CenteredRenderer::operator<<(char symbol) {
    if(heightCounter == centered.getHeight()) {
        return *this;
    }
    if(widthCounter == 0) {
        addLeftMargin();
        addLeftBorder();
        addLeftPadding();
    }
    addSymbol(symbol);
    ++widthCounter;
    if(widthCounter == centered.getWidth()) {
        widthReached();      
    }
    return *this;
}