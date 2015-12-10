#pragma once
#include "IndexAlgorithm.h"
#include "Downloader.h"

class IndexDJX : public IndexAlgorithm {
public:
	virtual void downloadData();
	virtual double calculateIndex(std::string date);
	static IndexDJX* createIndexDJX(Downloader* downloader);
	~IndexDJX();

private: 
	IndexDJX() {}
	Downloader* m_downloader;
};