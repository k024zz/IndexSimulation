#pragma once

#include "Decorator.h"
#include <string>

Decorator::Decorator(Simulator* Ds) {
	sim = Ds;
}

void Decorator::run(std::string date) {
	sim->run(date);
}