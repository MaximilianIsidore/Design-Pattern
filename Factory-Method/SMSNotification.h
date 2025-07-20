#pragma once
#include "Notification.h"
#include <iostream>

class SMSNotification : public Notification {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "Sending SMS to " << recipient
                  << ": " << message << std::endl;
    }
};