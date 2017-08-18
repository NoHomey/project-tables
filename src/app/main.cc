#include "../Renderer/Window/Window.h"
#include "../Renderer/BasicRenderer/BasicRenderer.h"
#include "Actions/Action/Action.h"

#include <unistd.h>

int main() {
    Window::syncSizes();
    Window::registerSignal();
    BasicRenderer::setup();

    Action::takeAction("Showtables");

    for(size_t i  = 0; i < 2; ++i) {
        if(Window::isResized()) {
            Window::syncSizes();
            Action::reRender();
        }
        sleep(2);
    }
    
    return 0;
}