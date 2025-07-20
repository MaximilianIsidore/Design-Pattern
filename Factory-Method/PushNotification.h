#pragma once
#include "Notification.h"
#include <iostream>

class PushNotification : public Notification {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "Sending PUSH to " << recipient
                  << ": " << message << std::endl;
    }
};