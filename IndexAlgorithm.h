#pragma once

#include <iostream>

class IndexAlgorithm {
public:
	virtual void downloadData() = 0;
	virtual double calculateIndex(std::string date) = 0;
};