#pragma once

#include <iostream>

using namespace std;

struct student
{
	int roolNumber; // it is by default public
};

union square
{
	int height; // Union size is highest var size here it is 4 Bytes
	int width;

	//Here both height and width refering same location so only when we need polymorphisom we can use it

};


//Bit Fields

//It is used to reduce the size of "class /struct"


struct Date
{
	unsigned int d : 5;  //Now size is 8 bytes 
	
	//unsigned int: 0; //force to fill next variable in new address
	

	unsigned int m : 4;
	unsigned int y;


};

int start()
{
	Date d;
	d.d = 8;
	d.m = 8;
	d.y = 1928;

	cout << sizeof(Date) << endl; // here it will take 12 Bytes

	//But Date 0-31 ==> it can be stored in 5 bits maximum value so we can slice using Bit fields
	//static Data member bitfields cannot be used
	//Array of Bit field not allowed


}