#pragma once
#include "Notification.h"
#include <iostream>

class EmailNotification : public Notification {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "Sending EMAIL to " << recipient
                  << ": " << message << std::endl;
    }
};