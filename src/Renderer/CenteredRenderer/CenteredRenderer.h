#pragma once

#include "../BasicRenderer/BasicRenderer.h"
#include "../Centered/Centered.h"

class CenteredRenderer: public CharOutputStream {
public:
    static CenteredRenderer& getRenderer() noexcept;

    static Centered& queryCentered(Window::size width, Window::size height) noexcept;

    static void clear();

public:
    CenteredRenderer() noexcept;
    
    CenteredRenderer(const CenteredRenderer&) = delete;
    
    CenteredRenderer& operator=(const CenteredRenderer&) = delete;

    CenteredRenderer(CenteredRenderer&&) = delete;
    
    CenteredRenderer& operator=(CenteredRenderer&&) = delete;

public:
    CharOutputStream& operator<<(char symbol) final;

private:
    static CenteredRenderer renderer;

    static void addHorizontalBorder(char symbol);

    static void addSymbol(char symbol);

    static void loopSymbol(Window::size count, char symbol);

    static void addTopMargin();

    static void addBottomMargin();

    static void addLeftMargin();

    static void addTopBorder();

    static void addLeftBorder();

    static void addRightBorder();

    static void addBottomBorder(); 

    static bool isVerticalMarginOdd() noexcept;

private:
    void widthReached();

    size_t calculatedRequiredBufferCapacity() const noexcept;

private:
    Window::size widthCounter;

    Window::size heightCounter;

    Centered centered;
};