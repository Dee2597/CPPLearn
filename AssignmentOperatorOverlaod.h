#pragma once


/*
Assignment Operator Overloading

When we have pointer in Member variable we should go for Assognment operator overloading

When we need Deep copy assignment operator overload needed



*/

#include <iostream>

using namespace std;


class Base
{
	int x;
public:
	Base(int x = 0) : x{ x } {}

	friend class Test;
};



class Test
{
	int* x;
public:
	Test(int val = 0): x{new int(val)}
	{
	}

	Test& operator =(const Test& rhs)
	{
		if (this != &rhs)
		{
			*x = *rhs.x;
		}
		return *this;
	}


	Test& operator = (const Base& rhs)
	{
		*x = rhs.x;
		return *this;
	}


	void setX(int val)
	{
		*x = val;
	}

	void print()
	{
		cout << "*x" << endl;
	}

	~Test() {
		delete x;
	}


};


int start()
{
	Test t1(10);
	Test t2;
	t2 = t1; // here it is shallow copy
	t1.setX(20);
	t1.print();
	t2.print();


	Base b(50);
	t2 = b;
	t2.print(); // here it will print 50
}


