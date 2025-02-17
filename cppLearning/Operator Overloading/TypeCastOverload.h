#pragma once


#include <iostream>

using namespace std;

class Dollar;

class Rupee
{
	double rupee;
public:
	Rupee(double d=0): rupee(d){}

	operator Dollar();
};



class Dollar
{
	double dollar;
public:
	Dollar(double d = 0) : dollar(d) {}

	operator Rupee()
	{
		return Rupee(dollar * 85);
	}
};

Rupee::operator Dollar()
{
	return Dollar(rupee / 85);
}


int static start()
{
	Dollar d(10);
	Rupee r;
	r = d;
	return 0;
}