#pragma once

#include "IndexAlgorithm.h"
#include "Simulator.h"
#include <iostream>
#include <string>

using namespace std;

class IndexSimulator : public Simulator {
public:
	virtual void run(string date);
	IndexSimulator(IndexAlgorithm* indexAlgorithm);
	void init();
	~IndexSimulator();

protected:
	
	IndexAlgorithm* m_indexAlgorithm;
};