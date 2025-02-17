#pragma once

#include <iostream>

using namespace std;

class Base
{
public:
	int x;
	static int y; //Declaration and common for all the object

	static void printY()
	{
		cout << "the value of Y is: " << y << endl;
		//Non static member variable we can't use
	}

};

int Base::y; //Defination to get memory

int start()
{
	Base b1;
	b1.x = 10;
	b1.y = 50;
	Base::y = 50;


	Base b2;
	b2.x = 20;
	b2.y = 60;

	Base::printY();

	//b1 and b2 "y" value will be 60.
}
