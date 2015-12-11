#pragma once
#include"Decorator.h"
#include"Simulator.h"
#include<iostream>
#include<string>
#include <fstream>
#include<map>


using namespace std;

class CompareDecorator :public Decorator{
public:
	CompareDecorator(Simulator* sim) : Decorator(sim) {};
	map<string, double> getRealIndexMap();
	virtual void run(string date);
};

