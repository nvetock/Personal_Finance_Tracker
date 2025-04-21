#include "Logger.h"
#include <fstream>
#include <ctime>
#include <chrono>

std::string logLevelToString(LogLevel level) {
	switch (level) {
	case LogLevel::DEBUG:       return "DEBUG";
	case LogLevel::INFO:        return "INFO";
	case LogLevel::WARNING:     return "WARNING";
	case LogLevel::ERROR:       return "ERROR";
	case LogLevel::CRITICAL:    return "CRITICAL";
	default:                    return "UNKNOWN";
	}
}


// Public Methods
// Standard log function for special cases if needed
void Logger::log(LogLevel level, const std::string& msg) const {
	std::ofstream logFile(_filename, std::ios::app);
	//explicit std::ofstream logFile(_filename, std::ios::app)

	if (logFile.is_open()) {
		auto now = std::chrono::system_clock::now();
		auto now_converted = std::chrono::system_clock::to_time_t(now);
		std::tm now_tm;
		localtime_s(&now_tm, &now_converted);

		logFile << std::put_time(&now_tm, "%Y-%m-%d | %H:%M:%S")
			<< " [" << logLevelToString(level) << "] " << msg << std::endl;
		logFile.close();
	}
	else {
		std::cerr << "Error: Unable to open log file: " << _filename << std::endl;
	}
}

// Quick log function
void Logger::debug(const std::string& msg) const { 
	Logger::log(LogLevel::DEBUG, msg);
}

void Logger::info(const std::string& msg) const { 
	Logger::log(LogLevel::INFO, msg);
}

void Logger::warning(const std::string& msg) const { 
	Logger::log(LogLevel::WARNING, msg);
}

void Logger::error(const std::string& msg) const { 
	Logger::log(LogLevel::ERROR, msg);
}

void Logger::critical(const std::string& msg) const { 
	Logger::log(LogLevel::CRITICAL, msg);
}