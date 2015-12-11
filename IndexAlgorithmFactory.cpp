#include "IndexAlgorithmFactory.h"

IndexAlgorithm* IndexAlgorithmFactory::createAlgorithm(AlgorithmType type, Downloader* downloader) {
	switch (type) {
	case DJI:
		return new IndexDJX(downloader);
		break;
	default:
		return NULL;
		break;
	}
}