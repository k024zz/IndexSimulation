#include "IndexDJX.h"

void IndexDJX::downloadData(){
	m_downloader->download();
}

double IndexDJX::calculateIndex(std::string date) {
	double adjustPrice = 0;
	for (auto stock : m_downloader->getStockPrice()) {
		adjustPrice += stock.second[date];
	}
	return adjustPrice / 0.14985889030177;
}

IndexDJX* IndexDJX::createIndexDJX(Downloader* downloader) {
	IndexDJX* indexDJX = new IndexDJX();
	indexDJX->m_downloader = downloader;
	return indexDJX;
}

IndexDJX::~IndexDJX() {
	if (m_downloader) {
		delete m_downloader;
		m_downloader = NULL;
	}
}