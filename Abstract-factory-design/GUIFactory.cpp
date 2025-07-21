#pragma once
#include "WindowsFactory.h"
#include "LinuxFactory.h"

std::unique_ptr<GUIFactory> GUIFactory::create(const std::string& type) {
    if (type == "windows") 
        return std::make_unique<WindowsFactory>();
    return std::make_unique<LinuxFactory>();
}