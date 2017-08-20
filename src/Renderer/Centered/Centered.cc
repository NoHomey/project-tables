#include "Centered.h"

Centered::Centered() noexcept
: width{0}, height{0}, hasBorder{false}, topMargin{0}, leftMargin{0} { }

Centered& Centered::reset(Window::size width, Window::size height) noexcept {
    this->width = width;
    this->height = height;
    hasBorder = false;
    topMargin = 0;
    leftMargin = 0;
    topPadding = 0;
    leftPadding = 0;
    return *this;
}

Centered& Centered::bordered() noexcept {
    hasBorder = true;
    return *this;
}

Centered& Centered::padding(Window::size top, Window::size left) noexcept {
    topPadding = top;
    leftPadding = left;
    return *this;
}

Centered& Centered::atLeastMargin(Window::size top, Window::size left) noexcept {
    topMargin = top;
    leftMargin = left;
    return *this;
}

Window::size Centered::calculateMargin(Window::size window, Window::size total) noexcept {
    return (window - total) / 2;
}

bool Centered::checkSize(Window::size margin, Window::size window, Window::size total) noexcept {
    if(margin != 0) {
        if(window < total) {
            return false;
        }
        if(calculateMargin(window, total) < margin) {
            return false;
        }
    } else if(total > window) {
        return false;
    }
    return true;
}

bool Centered::exec() const noexcept {
    return checkSize(topMargin, Window::getHeight(), totalHeight())
        && checkSize(leftMargin, Window::getWidth(), totalWidth());
}

Window::size Centered::getWidth() const noexcept {
    return width;
}

Window::size Centered::getHeight() const noexcept {
    return height;
}

bool Centered::isBordered() const noexcept {
    return hasBorder;
}

Window::size Centered::getTopMargin() const noexcept {
    return topMargin;
}
    
Window::size Centered::getLeftMargin() const noexcept {
    return leftMargin;
}

Window::size Centered::getTopPadding() const noexcept {
    return topPadding;
}
    
Window::size Centered::getLeftPadding() const noexcept {
    return leftPadding;
}

Window::size Centered::totalWidth() const noexcept {
    return width + (2 * hasBorder) + (2 * leftPadding) + 1; 
}

Window::size Centered::totalHeight() const noexcept {
    return height + (2 * hasBorder) + (2 * topPadding);
}

Window::size Centered::calculateTopMargin() const noexcept {
    return calculateMargin(Window::getHeight(), totalHeight());
}

Window::size Centered::calculateLeftMargin() const noexcept {
    return calculateMargin(Window::getWidth(), totalWidth());
}