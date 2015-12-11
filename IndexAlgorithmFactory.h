#pragma once

#include "IndexAlgorithm.h"
#include "IndexDJX.h"
#include "Downloader.h"

enum AlgorithmType
{
	DJI, SP500
};

class IndexAlgorithmFactory {
public:
	IndexAlgorithm* createAlgorithm(AlgorithmType type, Downloader* downloader);
};