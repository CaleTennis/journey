#include "Logger.hpp"

const char* Logger::whiteText = "\033[97m";
const char* Logger::redText = "\033[91m";
const char* Logger::greenText = "\033[92m";
const char* Logger::yellowText = "\033[93m";

void Logger::success(std::string const& message)
{
#ifdef DEBUG
	printf("%s%s%s\n", greenText, message.c_str(), whiteText);
#endif
}

void Logger::error(std::string const& message)
{
#ifdef DEBUG
	printf("%s%s%s\n", redText, message.c_str(), whiteText);
#endif
}

void Logger::warning(std::string const& message)
{
#ifdef DEBUG
	printf("%s%s%s\n", yellowText, message.c_str(), whiteText);
#endif
}