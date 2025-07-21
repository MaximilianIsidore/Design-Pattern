#include "GUIFactory.h"

void buildInterface(GUIFactory& factory) {
    auto frame = factory.createFrame();
    auto button = factory.createButton();
    auto label = factory.createLabel();
    
    frame->draw();
    button->draw();
    label->draw();
}

int main() {
    
    
    auto guiFactory = GUIFactory::create("windows");
    buildInterface(*guiFactory);
    
    return 0;
}