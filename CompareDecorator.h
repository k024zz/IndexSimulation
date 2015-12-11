#pragma once
#include"Decorator.h"
#include"Simulator.h"
#include<iostream>
using namespace std;

class CompareDecorator :public Decorator{
public:
	CompareDecorator(Simulator* sim) : Decorator(sim) {};
	virtual void run();
};

