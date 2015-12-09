#include "Logger.h"
#include <fstream>

Logger* Logger::instance = NULL;

Logger* Logger::getInstance() {
	if (instance == NULL) {
		instance = new Logger;
	}
	return instance;
}

void Logger::print(string text) {
	fstream file(LOGFILE, fstream::app);
	file << text.c_str();
	file.close();
}

void Logger::println(string text) {
	fstream file(LOGFILE, fstream::app);
	file << text.c_str() << endl;
	file.close();
}

Logger::~Logger() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}