#pragma once

#include <iostream>

using namespace std;


/*

Encapsulation:

It is a object oriented Programming concept which talks about binding together the data and the functions that manipulates those data
class is example

Abstracyion:

The process of hiding complex implementation details and only showing the essential features of a software to the user.
Abstraction is used to create user-defined data types for designing real-world objects.


Data Hiding:
The process of concealing internal data and preventing a program from directly accessing it. 
Data hiding is also known as data encapsulation.
It is implemented to have encapsulation in the program


Encapsulation is the process of hiding data and methods within a class, 
while abstraction is the process of hiding complex details and exposing only the essential features

*/

class Point
{
	double x, y;
public:

	//3 types of constructor

	Point() { x = 0; y = 0; };

	Point(double x, double y) : x{ x }, y{ y }
	{

	}

	Point(const Point& rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}

	double getX() const
	{
		return x;
	}

	double getY() const
	{
		return y;
	}


};

int start()
{
	Point p1(1, 2.2);

	Point p2;

	Point p3 = p1;

	p3.getY();

	return 0;

}



class Base
{
	int* x;
public:
	Base() :x{ nullptr } {}
	Base(int* x) : x{ x } {}

	~Base()
	{
		delete x;
		cout << "Destructor" << endl;
	}


};

int destructor()
{
	Base b(new int(10));
	return 0;
}



//Initializer list

//char x;
//int a;

//x(a) ==> if char passs to integer it will narrow data

//x{a} ==> it Will check narrowing  and throw warning


class initializeList
{
	char x;
	int y;
	const int z;
public:
	initializeList(int a, int b, int c) : x{ a }, y{ b }, z{c}
	{

	}
};


//This Pointer

//It is passed only to non static member function

//b2.get() ==> compiler changes to ==> Base::get(&b2);  ==> int get(Base * const this)

