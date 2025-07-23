#include "Logger.h"
using namespace std;

int main(){
    Logger* logger = Logger::getInstance();
    logger->logInfo("Application started");
    logger->logError("Database connection failed");
    
    // Different parts of application can access the same logger
    Logger* anotherLogger = Logger::getInstance();
    anotherLogger->logInfo("Same instance: " + 
                          std::to_string(logger == anotherLogger));
    return 0;
}