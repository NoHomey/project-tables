#include "Window.h"
#include <unistd.h>
#include <sys/ioctl.h>

Window Window::window;
sig_atomic_t Window::sizeChanged = 0;

Window::Window() noexcept
: width{0}, height{0} {}

const Window& Window::obtain() noexcept {
    return window;
}

Window::size Window::getWidth() noexcept {
    return window.width;
}

Window::size Window::getHeight() noexcept {
    return window.height;
}

void Window::syncSizes() noexcept {
    winsize windowSize;
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &windowSize) == 0) {
        window.width = windowSize.ws_col;
        window.height = windowSize.ws_row;
    }
    sizeChanged = 0;
}

void Window::registerSignal() {
    struct sigaction sigwinchAction;
    sigemptyset(&sigwinchAction.sa_mask);
    sigwinchAction.sa_flags = 0;
    sigwinchAction.sa_handler = sigwinchHandler;
    sigaction(SIGWINCH, &sigwinchAction, NULL);
}

void Window::sigwinchHandler(int) noexcept {
    sizeChanged = 1;
}

bool Window::isResized() noexcept {
    return sizeChanged == 1;
}