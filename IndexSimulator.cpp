#include "IndexSimulator.h"
#include <string>

void IndexSimulator::run() {
	init();
	string date;
	cout << "Input date:";
	while (date != "") {
		m_indexAlgorithm->calculateIndex(date);
		cin >> date;
	}
}

void IndexSimulator::init() {
	m_indexAlgorithm->downloadData();
}

IndexSimulator::IndexSimulator(IndexAlgorithm* indexAlgorithm) {
	m_indexAlgorithm = indexAlgorithm;
}