#include "Application.h"
#include <cstdio>
#include <thread>
#include "../../Renderer/Window/Window.h"
#include "../../Renderer/BasicRenderer/BasicRenderer.h"
#include "../Actions/Action/Action.h"
#include "../Actions/ShowTables/ShowTables.h"
#include "../Actions/Describe/Describe.h"
#include "../Actions/Rename/Rename.h"
#include "../Actions/CreateTable/CreateTable.h"
#include "../Actions/AddColumn/AddColumn.h"
#include "../Actions/Save/Save.h"
#include "../Actions/Insert/Insert.h"
#include "../Actions/Count/Count.h"
#include "../Actions/Delete/Delete.h"
#include "../Actions/Help/Help.h"
#include "../Actions/Quit/Quit.h"

std::mutex Application::renderMutex;

volatile bool Application::stop = false;

void Application::run() {
    Window::syncSizes();
    Window::registerSignal();
    BasicRenderer::setup();
    BasicRenderer::getRenderer().clearWindow();

    Action::Commands commands{11};
    commands.registerCommand<ShowTables>();
    commands.registerCommand<Describe>();
    commands.registerCommand<Rename>();
    commands.registerCommand<CreateTable>();
    commands.registerCommand<AddColumn>();
    commands.registerCommand<Save>();
    commands.registerCommand<Insert>();
    commands.registerCommand<Count>();
    commands.registerCommand<Delete>();
    commands.registerCommand<Help>();
    commands.registerCommand<Quit>();
    Action::registerCommands(std::move(commands));

    std::thread reader{readFromStdin};
    std::thread reRenderer{reRenderOnWidnowResize};

    reader.join();
    reRenderer.join();
}

void Application::quit() {
    stop = true;
}

void Application::reRenderOnWidnowResize() {
    while(!stop) {
        if(Window::isResized()) {
            std::unique_lock<std::mutex> lock{renderMutex};
            Window::syncSizes();
            Action::reRender();
        } else {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1s);
        }
    }
}

void Application::readFromStdin() {
    DynamicArray<char> inputBuffer{initialCapacityOfBuffer};
    char symbol;
    while(!stop) {
        symbol = std::getchar();
        if(symbol == '\n') {
            std::unique_lock<std::mutex> lock{renderMutex};
            Action::takeAction({inputBuffer.data(), inputBuffer.size()});
            inputBuffer.empty();
        } else {
            inputBuffer.push(symbol);
        }
    }
}