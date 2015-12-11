#pragma once

#include "Simulator.h"

class Decorator :public Simulator {
		Simulator* sim;
public:
	Decorator(Simulator* Ds);
	void run();
};

