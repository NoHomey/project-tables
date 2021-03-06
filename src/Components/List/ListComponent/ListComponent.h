#pragma once

#include "../ListModel/ListModel.h"
#include "../../ComponentWithPolymorphicModel/ComponentWithPolymorphicModel.htd"
#include "../../../Renderer/Window/Window.h"

class ListComponent: public ComponentWithPolymorphicModel<ListModel> {
public:
    void render() final;

public:
    ListComponent(const ListModel* model) noexcept;

    ~ListComponent() noexcept = default;

    ListComponent(const ListComponent& other) = delete;

    ListComponent(ListComponent&& other) = delete;

    ListComponent& operator=(const ListComponent& other) = delete;

    ListComponent& operator=(ListComponent&& other) = delete;

private:
    static void loopSymbol(Window::size count, char symbol);

    static void addPadding(Window::size padding);
    
    static void addText(const String& text);

private:
    void calculateMinWidth() noexcept;

    void addLine(const String& text);

    void addTitle();

    void addItems();

    void renderList(Window::size padding);

private:
    static const  Window::size maxHorizontalPadding = 5;

private:
    Window::size minWidth;

    Window::size minHeight;

    Window::size width;

    Window::size leftPadding;
};