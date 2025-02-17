#pragma once
#include <iostream>

// In Array ArrayName[4] == 4[ArrayName]  because compiler read as *(ArrayName+4) == ArrayName is Address of 0th location

/*

2 DIm Array

int Matrix [][2] = { {1, 2} , {2,4}};
*/



// 2 Dim array while passing to Fn should be written column size

const int c = 2;
void fun(int arr[][c], int r)
{
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
		{
			std::cout << arr[i][j];
		}

	}
}

//other way

void fun(int* arr, int r, int c)
{
	//cout << *(arr + i * c + j); //to access location
}


//Calling function like below
//  
// fun((int*)arr, 2, 2);


void fun1(int arr[])
{

}

void fun1(int* arr)
{
	//*(arr+i)
}