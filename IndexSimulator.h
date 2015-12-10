#pragma once

#include "IndexAlgorithm.h"
#include <iostream>
using namespace std;

class IndexSimulator {
public:
	void run();
	IndexSimulator(IndexAlgorithm* indexAlgorithm);

private:
	void init();
	IndexAlgorithm* m_indexAlgorithm;
};