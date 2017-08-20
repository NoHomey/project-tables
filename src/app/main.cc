#include "../Renderer/Window/Window.h"
#include "../Renderer/BasicRenderer/BasicRenderer.h"
#include "Actions/Action/Action.h"

#include <unistd.h>

int main() {
    Window::syncSizes();
    Window::registerSignal();
    BasicRenderer::setup();

    Action::__mock();

    Action::takeAction("Showtables");
    sleep(2);
    Action::takeAction("Describe Table");

    /*for(size_t i  = 0; i < 2; ++i) {
        if(Window::isResized()) {
            Window::syncSizes();
            Action::reRender();
        }
        sleep(2);
    }*/
    
    return 0;
}