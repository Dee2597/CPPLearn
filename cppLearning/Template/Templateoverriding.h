#pragma once

#include<iostream>

using namespace std;

int const& getMax(const int& x, const int& y)
{
	cout << "int Type getMax()" << endl;
	return x > y ? x : y;
}




template <class T>
T const& getMax(const T& x, const T& y)
{
	cout << "template Type getMax(T, T)" << endl;
	return x > y ? x : y;

}


template <class T>
T const& getMax(const T& x, const T& y, const T&  z)
{
	cout << "template Type getMax(T, T, T)" << endl;
	return getMax(getMax(x, y), z);

}


int start()
{

	getMax(2, 3);
	getMax(2.0, 3.0);
	getMax<>(2, 3);
	getMax<>(2.0, 3.0);
	getMax<double>(2, 3);
	getMax<int>(2.5, 3.0);
	getMax(2, 3, 4);
	return 0;


	/*
	* 
	*Output

int Type getMax()
template Type getMax(T, T)
template Type getMax(T, T)
template Type getMax(T, T)
template Type getMax(T, T)
template Type getMax(T, T)
template Type getMax(T, T, T)
int Type getMax()
int Type getMax()
	*/
}
