#pragma once

/*
There are two types of polymorphism
 1. Compile time polymorphism / static Binding /Early Binding

   a. Function overloading
   b. Operator Overloading

2. Runtime Polymorphism  / Dynamic Binding / Lazy Binding

2. Function Overridng (Virtual Function)



*/


#include <iostream>

using namespace std;

class IBase
{
public:
	virtual void Check() = 0;
};

void IBase::Check()
{
	cout << "IBase Chjecked" << endl;
}

class Base: public IBase
{
public:
	virtual void fun(int x)
	{
		cout << "Base" << endl;
	}

	void Check()
	{
		cout << "Base Fn Checked" << endl;
	}
};

class Derived : public Base
{
public:
	void fun(int x) override  // override keyword will check while compile is function variable matching or not through error
	{
		cout << "Derived" << endl;
	}
};

int start()
{
	Base *b = new Derived();
	b->fun(1.5); // return Derived


	Derived d;
	Base& k = d;
	k.fun(2);

	IBase* p = new Derived();
	p->Check();

	return 0;

	//virtual function only possible using pinter and Reference

}

//