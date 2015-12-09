#pragma once

#include <iostream>
#include <fstream>
using namespace std;
// singleton patterm for Logger

#define LOGFILE "log.txt"

class Logger {
private:
	Logger() {}
	static Logger* instance;
	FILE* file;

public:
	static Logger* getInstance();
	void print(string text);
	void println(string text);
	~Logger();
};
