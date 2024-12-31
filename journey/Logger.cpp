#include "Logger.hpp"

const char* Logger::redText = "\033[91m";
const char* Logger::greenText = "\033[92m";
const char* Logger::yellowText = "\033[93m";
const char* Logger::cyanText = "\033[96m";
const char* Logger::whiteText = "\033[97m";


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

void Logger::info(std::string const& message)
{
#ifdef DEBUG
	printf("%s%s\n", whiteText, message.c_str());
#endif
}

void Logger::game(std::string const& message)
{
#ifdef DEBUG
	printf("%s%s%s\n", cyanText, message.c_str(), whiteText);
#endif
}