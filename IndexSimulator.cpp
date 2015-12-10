#include "IndexSimulator.h"
#include <string>

void IndexSimulator::run() {
	init();
	string date;
	cout << "Input date(YYYY-MM-DD): ";
	cin >> date;
	while (date != "exit") {
		cout << m_indexAlgorithm->calculateIndex(date) << endl;
		cout << "Input date(YYYY-MM-DD): ";
		cin >> date;
	}
}

void IndexSimulator::init() {
	m_indexAlgorithm->downloadData();
}

IndexSimulator::IndexSimulator(IndexAlgorithm* indexAlgorithm) {
	m_indexAlgorithm = indexAlgorithm;
}

IndexSimulator::~IndexSimulator() {
	if (m_indexAlgorithm) {
		delete m_indexAlgorithm;
		m_indexAlgorithm = NULL;
	}
}