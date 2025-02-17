#pragma once

#include <iostream>

using namespace std;

// Multiple Derived class inheriting same Base

// Base *b = new d1() --> interface --  helps to achieve Dynamic Binding it will happen if Base is virtual



class Human
{
	void breathing()
	{
		cout << "I'm breathing" << endl;
	}
};

class Youtuber : public Human
{
	void work()
	{
		cout << "creating videos" << endl;
	}
};

class Engineer : public Human
{
	void work()
	{
		cout << "working on Project" << endl;
	}
};

class Doctor : public Human
{
	void work()
	{
		cout << "Saving a grand Mother" << endl;
	}
};


