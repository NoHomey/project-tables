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
    Action::takeAction("Showtabless");
    sleep(2);
    Action::takeAction("Describe AAA");
    sleep(2);
    Action::takeAction("Rename AAA III");
    sleep(2);
    Action::takeAction("Showtables");
    sleep(2);
    Action::takeAction("Rename III III");
    sleep(2);
    Action::takeAction("Showtables");
    sleep(2);
    Action::takeAction("Rename III Ivo");
    sleep(2);
    Action::takeAction("Showtables");
    sleep(2);
    Action::takeAction("Rename IIII Ivo");
    sleep(2);
    Action::takeAction("Showtables");
    sleep(2);
    Action::takeAction("Rename III ");
    sleep(2);
    Action::takeAction("Showtables");

    /*for(size_t i  = 0; i < 2; ++i) {
        if(Window::isResized()) {
            Window::syncSizes();
            Action::reRender();
        }
        sleep(2);
        Action::takeAction("Showtabless");
        sleep(2);
        Action::takeAction("Describe AAA");
    }*/
    
    return 0;
}