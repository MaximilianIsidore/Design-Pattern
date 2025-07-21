#pragma once
#include "GUIFactory.h"

class LinuxFactory : public GUIFactory {
private:
    class LinuxFrame : public Frame {
    public:
        void draw() const override { 
            std::cout << "I'm a Linux-like frame" << std::endl; 
        }
    };
    
    class LinuxButton : public Button {
    public:
        void draw() const override { 
            std::cout << "I'm a Linux-like button" << std::endl; 
        }
    };
    
    class LinuxLabel : public Label {
    public:
        void draw() const override { 
            std::cout << "I'm a Linux-like label" << std::endl; 
        }
    };

public:
    std::unique_ptr<Frame> createFrame() override { 
        return std::make_unique<LinuxFrame>(); 
    }
    std::unique_ptr<Button> createButton() override { 
        return std::make_unique<LinuxButton>(); 
    }
    std::unique_ptr<Label> createLabel() override { 
        return std::make_unique<LinuxLabel>(); 
    }
};
