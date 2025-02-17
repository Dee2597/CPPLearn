#pragma once

#include <iostream>

using namespace std;

/*
a. places we can use Templates
1. Fubction template
2.Class Templates

b. Templates are way to write generic program

c. We pass data type as parameter to function or class

*/


//template <class T>
// template class T1, class T2> // if both variable different data type



template <typename T>
T getMax(T x, T y)
{
	cout << "normal template called " << endl;
	return x > y ? x : y;
}

/*template <class T1, class T2, class T3>
T1 getMax(T2 x, T3 y)
{
	cout << "Return type called" << endl;
	return x > y ? x : y;
}*/


// if you don't want mention return type in template you can write like this
template <class T1, class T2>
auto getMax(T1 x, T2 y)
{
	cout << "Auto template called " << endl;
	return x > y ? x : y;
}



int start()
{
	int x = 10; int y = 20;

	getMax<char>(x, y); //T will replace by int  it not necessary if data type is match with T

	char c1 = 'a'; char c2 = 'v';

	getMax(c1, c2);


	getMax<double>(20.5, 11); // it will call second function and here<double> will refers to return type

	return 0;



}
