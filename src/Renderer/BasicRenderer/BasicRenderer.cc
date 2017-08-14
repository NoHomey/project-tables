#include "BasicRenderer.h"
#include <cstdio>
#include <unistd.h>

const char* const BasicRenderer::CLEAR = "\033[H\033[2J";

const size_t  BasicRenderer::CLEAR_LENGTH = 8;

BasicRenderer BasicRenderer::renderer;

void BasicRenderer::setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
}

BasicRenderer& BasicRenderer::getRenderer() noexcept {
    return renderer;
}

void BasicRenderer::ensureCapacity(size_t capacity) {
    buffer.ensureCapacity(CLEAR_LENGTH + capacity);
}

BasicRenderer& BasicRenderer::operator<<(char symbol) {
    buffer.push(symbol);
    return *this;
}

void BasicRenderer::clear() {
    buffer.empty();
    for(size_t i = 0; i < CLEAR_LENGTH; ++i) {
        buffer.push(CLEAR[i]);
    }
}

void BasicRenderer::render() const {
    write(STDOUT_FILENO, buffer.data(), buffer.size());
}