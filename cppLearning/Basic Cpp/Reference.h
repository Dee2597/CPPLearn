#pragma once

//ref Data Member of class

//Use when you are ok you are Data member changed without your knowledge
// Assignment operator not allowed (when you do copy constructor because of the reference both newly  created object member variable point towards base object value)
//You need to ensure that the refered object is guaranteed to exist till yur class object exist (Reference variable delete before object)

#include <iostream>
using namespace std;

class Base
{
	int& x;
public:
	Base(int& x) : x(x){}
	void print()
	{
		cout << x << endl;
	}

	Base& operator=(const Base& obj)
	{
		x = obj.x;
		return *this;
	}
};


/*
int main()
{
int val = 10;
Base b(val);
val = 20;
int x = 30;
Base b1(x);
b1 = b; /// Now x value changes to  20;
//You can change private memeber variable as well as

int *var = new int(10);
Base exist(*var);
delete var;

Now Member variable reference delete

*/