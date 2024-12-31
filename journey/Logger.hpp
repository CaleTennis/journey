#pragma once
#include <string>
#include <iostream>

#define DEBUG 1

class Logger
{
	Logger() = delete; // Log should not be created

public:
	static void error(std::string const& message);
	static void success(std::string const& message);
	static void warning(std::string const& message);

private:
	static const char* whiteText;
	static const char* redText;
	static const char* greenText;
	static const char* yellowText;
};