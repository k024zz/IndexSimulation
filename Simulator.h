#pragma once

#include <string>

class Simulator {
public:
	virtual void run(std::string date) = 0;
};
