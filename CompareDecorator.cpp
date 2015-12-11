#pragma once
#include"CompareDecorator.h"

void CompareDecorator::run() {
	Decorator::run();
	cout << "hello world" << endl;
}