#pragma once

#include "../InfoModel/InfoModel.h"
#include "../../Component.h"
#include "../../../Renderer/Window/Window.h"

class InfoComponent: public Component {
private:
    struct Ratio {
        Window::size numerator;
        Window::size denominator;
    };

public:
    static InfoComponent* inject(const InfoModel* model) noexcept;

private:
    InfoComponent() noexcept;

    InfoComponent(const InfoComponent& other) = delete;

    InfoComponent(InfoComponent&& other) = delete;

    InfoComponent& operator=(const InfoComponent& other) = delete;

    InfoComponent& operator=(InfoComponent&& other) = delete;

public:
    void render() final;

private:
    void setModel(const InfoModel* infoModel) noexcept;

    bool calculateSizes() noexcept;

    void fillEmpty(Window::size count) const;

    void endLastLine() const;

    void fillEmptyLine() const;

    void fillEmpty() const;

private:
    static Window::size calculateRatio(Window::size size, unsigned short index) noexcept;

private:
    static InfoComponent component;

    static const unsigned int ratiosCount = 5;

    static const Ratio ratios[ratiosCount];

private:
    const InfoModel* model;

    Window::size width;

    Window::size height;

    Window::size lastLineLength;

    Window::size linesCount;
};