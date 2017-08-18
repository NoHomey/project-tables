#pragma once

#include "../ListModel/ListModel.h"
#include "../../Component.h"
#include "../../../Renderer/Window/Window.h"

class ListComponent: public Component {
public:
    static ListComponent* inject(const ListModel* model) noexcept;

public:
    void render() final;

private:
    ListComponent() noexcept;

    ListComponent(const ListComponent& other) = delete;

    ListComponent(ListComponent&& other) = delete;

    ListComponent& operator=(const ListComponent& other) = delete;

    ListComponent& operator=(ListComponent&& other) = delete;

private:
    static void loopSymbol(Window::size count, char symbol);

    static void addPadding(Window::size padding);
    
    static void addText(const String& text);

private:
    void setModel(const ListModel* listModel) noexcept;

    void calculateMinWidth() noexcept;

    void addLine(const String& text);

    void addTitle();

    void addItems();

    void renderList(Window::size padding);

private:
    static ListComponent component;

private:
    const ListModel* model;

    Window::size minWidth;

    Window::size minHeight;

    Window::size width;

    Window::size leftPadding;
};