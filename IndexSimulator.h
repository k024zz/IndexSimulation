#pragma once

#include "IndexAlgorithm.h"
#include <iostream>
using namespace std;

class IndexSimulator {
public:
	void run();
	IndexSimulator(IndexAlgorithm* indexAlgorithm);
	~IndexSimulator();

private:
	void init();
	IndexAlgorithm* m_indexAlgorithm;
};