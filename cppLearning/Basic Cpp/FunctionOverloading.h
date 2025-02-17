#pragma once

#include <iostream>

using namespace std;



void print(int x)
{
	cout<<"first"<<endl;
}

void print(char c)
{
	cout << "second" << endl;
}

int add(int x, int y)
{
	return x + y;
}

int add(int x, int y, int z=0)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}


//CONST:

//C++ Allows to overload member function on the basis of const and non - const

// const parameter allows to overload member function and normal function but it should be reference or pointer


int fun(const int* a)
{

}

int fun(int* a)
{

}






//compiler will rename if both function same to resolve it


//Cannot overload with written Type only

//int add(int, int);
//void add(int, int); // will throw error


// if one is static and other is non static then it won't work

/*Array of pointer or Array both are similar

int add(int arr[]);

int add(*arr);

*/



/*


const and volatile doesn't make difference


int add(const int a);

int add (int a);

int add(volatile int p);a;; All are same


*/


/*

Both the function are same difffer by Default parameter then it won't work

*/

