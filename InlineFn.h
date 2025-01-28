#pragma once

#include <iostream>

using namespace std;

inline void PrintME(string str)
{
	cout << str << endl;
}

int Call()
{
	for (int i = 0; i < 10000; i++)
	{
		PrintME("Hi Dee");
		return 0;
	}
}

//No need stop call create stack to run function. instead of that it willr eplace in main function
