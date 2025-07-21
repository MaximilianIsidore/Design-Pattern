#pragma once
#include "GUIFactory.h"

class WindowsFactory : public GUIFactory {
private:
    class WindowsFrame : public Frame {
    public:
        void draw() const override { 
            std::cout << "I'm a Windows-like frame" << std::endl; 
        }
    };
    
    class WindowsButton : public Button {
    public:
        void draw() const override { 
            std::cout << "I'm a Windows-like button" << std::endl; 
        }
    };
    
    class WindowsLabel : public Label {
    public:
        void draw() const override { 
            std::cout << "I'm a Windows-like label" << std::endl; 
        }
    };

public:
    std::unique_ptr<Frame> createFrame() override { 
        return std::make_unique<WindowsFrame>(); 
    }
    std::unique_ptr<Button> createButton() override { 
        return std::make_unique<WindowsButton>(); 
    }
    std::unique_ptr<Label> createLabel() override { 
        return std::make_unique<WindowsLabel>(); 
    }
};