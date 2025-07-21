#pragma once

#include  "GUIComponent.h"

class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Frame> createFrame() = 0;
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<Label> createLabel() = 0;
    
    static std::unique_ptr<GUIFactory> create(const std::string& type);
};

