#pragma once

#include <iostream>
#include "Downloader.h"

class IndexAlgorithm {
public:
	virtual void downloadData() = 0;
	virtual double calculateIndex(std::string date) = 0;
protected:
	Downloader* m_downloader;
};