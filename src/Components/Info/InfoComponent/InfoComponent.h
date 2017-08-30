#pragma once

#include "../InfoModel/InfoModel.h"
#include "../../ComponentWithPolymorphicModel/ComponentWithPolymorphicModel.htd"
#include "../../../Renderer/Window/Window.h"

class InfoComponent: public ComponentWithPolymorphicModel<InfoModel> {
private:
    struct Ratio {
        Window::size numerator;
        
        Window::size denominator;
    };

public:
    InfoComponent(const InfoModel* model) noexcept;

    InfoComponent(const InfoComponent& other) = delete;

    InfoComponent(InfoComponent&& other) = delete;

    InfoComponent& operator=(const InfoComponent& other) = delete;

    InfoComponent& operator=(InfoComponent&& other) = delete;

public:
    void render() final;

private:
    bool calculateSizes() noexcept;

    void fillEmpty(Window::size count) const;

    void endLastLine() const;

    void fillEmptyLine() const;

    void fillEmpty() const;

private:
    static Window::size calculateRatio(Window::size size, unsigned short index) noexcept;

private:
    static const unsigned int ratiosCount = 5;

    static const Ratio ratios[ratiosCount];

private:
    Window::size width;

    Window::size height;

    Window::size lastLineLength;

    Window::size linesCount;
};