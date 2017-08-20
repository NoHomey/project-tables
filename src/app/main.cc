#include "../Renderer/Window/Window.h"
#include "../Renderer/BasicRenderer/BasicRenderer.h"
#include "../Components/Info/InfoComponent/InfoComponent.h"

#include <unistd.h>

class Mock: public InfoModel {
public:
    Mock(size_t count) noexcept: count{count} { }

    size_t textLength() const noexcept {
        return count;
    }

    void output(CharOutputStream& outputStream) const {
        for(size_t i  = 0; i < count; ++i) {
            outputStream << 'A';
        }
    }

private:
    size_t count;
};

int main() {
    Window::syncSizes();
    Window::registerSignal();
    BasicRenderer::setup();

    Mock mock{200};
    InfoComponent::inject(&mock)->render();

   
    
    return 0;
}