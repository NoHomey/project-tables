#include "InfoModel.h"

InfoModel::InfoModel(size_t length) noexcept
: length{length} { }

size_t InfoModel::textLength() const noexcept {
    return length;
}

void InfoModel::releaseResources() noexcept { }

void InfoModel::setTextLength(size_t textLength) noexcept {
    length = textLength;
}