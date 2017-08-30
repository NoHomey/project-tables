#include "InfoModel.h"

InfoModel::InfoModel(size_t length, bool deletable) noexcept
: PolymorphicModel{deletable}, length{length} { }

size_t InfoModel::textLength() const noexcept {
    return length;
}