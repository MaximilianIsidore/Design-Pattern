#pragma once
#include "Notification.h"
#include "EmailNotification.h"
#include "SMSNotification.h"
#include "PushNotification.h"
#include <memory>
#include <string>

class NotificationFactory {
public:
    enum class Type { EMAIL, SMS, PUSH };

    static std::unique_ptr<Notification> createNotification(Type type) {
        switch (type) {
            case Type::EMAIL:
                return std::make_unique<EmailNotification>();
            case Type::SMS:
                return std::make_unique<SMSNotification>();
            case Type::PUSH:
                return std::make_unique<PushNotification>();
            default:
                return nullptr;
        }
    }
};