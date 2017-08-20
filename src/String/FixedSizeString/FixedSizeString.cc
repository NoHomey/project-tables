#include "FixedSizeString.h"
#include <utility>

void FixedSizeString::fill(const char* content) noexcept {
    for(size_t index = 0; index < stringLength; ++index) {
        string[index] = content[index];
    }
    string[stringLength] = '\0';
    filled = stringLength;
}

FixedSizeString::FixedSizeString() noexcept
: String{}, filled{0} { }

FixedSizeString::FixedSizeString(const size_t length)
: String{(length > 0 ? new char[length + 1] : nullptr), length}, filled{0} { }

FixedSizeString::FixedSizeString(const char* content, size_t length)
: FixedSizeString{length} {
    fill(content);
}

FixedSizeString::FixedSizeString(const char* content)
: filled{0} {
    const size_t length = calculateLength(content);
    string = new char[length + 1];
    stringLength = length;
    fill(content);
}

FixedSizeString::~FixedSizeString() noexcept {
    delete[] string;
}

FixedSizeString::FixedSizeString(FixedSizeString&& other) noexcept
: String{std::move(other)} {}

FixedSizeString& FixedSizeString::operator=(FixedSizeString&& other) noexcept {
    if(this != &other) {
        delete[] string;
        String::operator=(std::move(other));
        filled = other.filled;
    }
    return *this;
}

bool FixedSizeString::isntFilled() const noexcept {
    return filled < stringLength;
}

bool FixedSizeString::isFilled() const noexcept {
    return filled == stringLength;
}

FixedSizeString& FixedSizeString::operator<<(const char symbol) noexcept {
    if(isntFilled()) {
        string[filled] = symbol;
        ++filled;
        if(isFilled()) {
            string[stringLength] = '\0';
        }
    }
    return *this;
}