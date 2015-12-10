#pragma once
#include "IndexAlgorithm.h"

class IndexDJX : public IndexAlgorithm {
public:
	virtual void downloadData();
	virtual double calculateIndex(std::string date);
};