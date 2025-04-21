#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include<string>

enum class LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

std::string logLevelToString(LogLevel level);

class Logger {
public:
	Logger(const std::string& filename)
		: _filename{ filename }
	{ }


	// Standard log function for special cases if needed
	void log(LogLevel level, const std::string& msg) const;

	// Quick log function
	void debug(const std::string& msg) const;
	void info(const std::string& msg) const;
	void warning(const std::string& msg) const;
	void error(const std::string& msg) const;
	void critical(const std::string& msg) const;

private:
	std::string _filename{};
};
#endif