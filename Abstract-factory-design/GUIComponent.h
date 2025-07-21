#pragma once

#include <iostream>
#include <memory>

/* Abstract Product Interfaces */
class GUIComponent {
public:
    virtual ~GUIComponent() = default;
    virtual void draw() const = 0;
};

class Frame : public GUIComponent {};
class Button : public GUIComponent {};
class Label : public GUIComponent {};