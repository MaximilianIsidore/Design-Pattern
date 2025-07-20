#include "NotificationFactory.h"

int main() {
    auto emailNotifier = NotificationFactory::createNotification(NotificationFactory::Type::EMAIL);
    emailNotifier->send("alice@example.com", "Hello, Alice!");

    auto smsNotifier = NotificationFactory::createNotification(NotificationFactory::Type::SMS);
    smsNotifier->send("+1234567890", "Hi there!");

    auto pushNotifier = NotificationFactory::createNotification(NotificationFactory::Type::PUSH);
    pushNotifier->send("device_token_abc", "You have a new alert!");

    return 0;
}