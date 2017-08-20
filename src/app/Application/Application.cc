#include "Application.h"
#include <cstdio>
#include <thread>
#include "../../Renderer/Window/Window.h"
#include "../../Renderer/BasicRenderer/BasicRenderer.h"
#include "../Actions/Action/Action.h"

ConstString Application::quitString{"quit"};

std::mutex Application::commandMutex;

std::condition_variable Application::condition;

bool Application::readCommand = false;

ImmutableString Application::command;

volatile bool Application::stop = false;

void Application::run() {
    Window::syncSizes();
    Window::registerSignal();
    BasicRenderer::setup();
    BasicRenderer::getRenderer().clearWindow();

    std::thread reader{readFromStdin};
    std::thread commandInterpreter{takeAction};
    std::thread reRenderer{reRenderOnWidnowResize};

    reader.join();
    commandInterpreter.join();
    reRenderer.join();
}

void Application::reRenderOnWidnowResize() {
    while(!stop) {
        if(Window::isResized()) {
            Window::syncSizes();
            Action::reRender();
        } else {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1s);
        }
    }
}

bool Application::waitForAction() {
    return !readCommand;
}

void Application::readFromStdin() {
    DynamicArray<char> inputBuffer{initialCapacityOfBuffer};
    char symbol;
    while(true) {
        symbol = std::getchar();
        if(symbol == '\n') {
            if((inputBuffer.size() == 4)
                && (ConstString{inputBuffer.data(), inputBuffer.size()} == quitString)) {
                stop = true;
                return;
            }
            std::unique_lock<std::mutex> lock{commandMutex};
            command = {inputBuffer.data(), inputBuffer.size()};
            readCommand = true;
            condition.wait(lock, waitForAction);
            inputBuffer.empty();
        } else {
            inputBuffer.push(symbol);
        }
    }
}

void Application::takeAction() {
    while(!stop) {
        std::unique_lock<std::mutex> lock{commandMutex};
        if(readCommand) {
            Action::takeAction(command);
            readCommand = false;
            condition.notify_one();
        }
    }
}