#pragma once

#include "IndexAlgorithm.h"
#include "Simulator.h"
#include <iostream>
using namespace std;

class IndexSimulator : public Simulator {
public:
	virtual void run();
	IndexSimulator(IndexAlgorithm* indexAlgorithm);
	~IndexSimulator();

protected:
	void init();
	IndexAlgorithm* m_indexAlgorithm;
};