#include "Decorator.h"

Decorator::Decorator(Simulator* Ds) {
	sim = Ds;
}

void Decorator::run() {
	sim->run();
}