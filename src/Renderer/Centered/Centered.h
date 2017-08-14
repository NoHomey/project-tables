#pragma once

#include "../Window/Window.h"

class Centered {
public:
    Centered() noexcept;

public:
    Centered& reset(Window::size width, Window::size height) noexcept;

    Centered& bordered() noexcept;

    Centered& atLeastMargin(Window::size top, Window::size left) noexcept;

    bool exec() const noexcept;

    Window::size getWidth() const noexcept;

    Window::size getHeight() const noexcept;

    bool isBordered() const noexcept;

    Window::size getTopMargin() const noexcept;
    
    Window::size getLeftMargin() const noexcept;

    Window::size totalWidth() const noexcept;

    Window::size totalHeight() const noexcept;

    Window::size calculateTopMargin() const noexcept;
    
    Window::size calculateLeftMargin() const noexcept;

private:
    static Window::size calculateMargin(Window::size window, Window::size total) noexcept;

    static bool checkSize(Window::size margin, Window::size window, Window::size total) noexcept;

private:
    Window::size width;

    Window::size height;

    bool hasBorder;

    Window::size topMargin;

    Window::size leftMargin;
};