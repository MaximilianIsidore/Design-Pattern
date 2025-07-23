#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <ctime>

class Logger {
private:
    static Logger* instance;
    static std::mutex mutex_;
    std::ofstream logFile;
    
    Logger() {
        logFile.open("application.log", std::ios::app);
        std::cout << "Logger initialized" << std::endl;
    }
    
    std::string getCurrentTime() {
        time_t now = time(0);
        char* timeStr = ctime(&now);
        std::string result(timeStr);
        result.pop_back(); // Remove newline
        return result;
    }
    
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }
    
    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        std::string logEntry = "[" + getCurrentTime() + "] " + message;
        
        std::cout << logEntry << std::endl;
        if (logFile.is_open()) {
            logFile << logEntry << std::endl;
            logFile.flush();
        }
    }
    
    void logInfo(const std::string& message) {
        log("INFO: " + message);
    }
    
    void logError(const std::string& message) {
        log("ERROR: " + message);
    }
    
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

Logger* Logger::instance = nullptr;
std::mutex Logger::mutex_;
