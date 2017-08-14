#pragma once

#include <signal.h>

class Window {
public:
    using size = unsigned short;

public:
    Window(const Window&) = delete;
    
    Window& operator=(const Window&) = delete;

    Window(Window&) = delete;
    
    Window& operator=(Window&) = delete;

public:
    static size getWidth() noexcept;

    static size getHeight() noexcept;

    static const Window& obtain() noexcept;

    static void syncSizes() noexcept;

    static void registerSignal();

    static bool isResized() noexcept;

private:
    void static sigwinchHandler(int) noexcept;

private:
    static Window window;

    static sig_atomic_t sizeChanged;

private:
    Window() noexcept;

private:
    size width;

    size height;
};