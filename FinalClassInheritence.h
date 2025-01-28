#pragma once

#include <iostream>

using namespace std;

//Make class No inheritable without using Final Keyword

/*
solution

1. Make Default constructor as private --  we can't create object
2. Inherite Final class as virtual
3. Make our class friend inside Final class



*/


class Final
{
private:
	Final()
	{

	}
	friend class Base;
};

//  because of this virtual object refered directly to Final class from Derived 
// but final class is private constructor so it doesn't allow to create object

class Base: virtual public Final 
{
public:
	Base(){}
};

class Derived : public Base
{
public:
	//Derived(){}
};



