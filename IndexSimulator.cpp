#include "IndexSimulator.h"
#include <string>

void IndexSimulator::run(string date) {
	
	if(date != "exit")
		cout <<"Calculated Index: "<< m_indexAlgorithm->calculateIndex(date) <<endl;
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