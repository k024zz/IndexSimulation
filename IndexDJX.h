#pragma once
#include "IndexAlgorithm.h"
#include "Downloader.h"

class IndexDJX : public IndexAlgorithm {
public:
	virtual void downloadData();
	virtual double calculateIndex(std::string date);
	IndexDJX(Downloader* downloader);
	~IndexDJX();
};