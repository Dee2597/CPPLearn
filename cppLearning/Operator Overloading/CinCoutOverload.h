#pragma once

#include <iostream>

using namespace std;

//cout<<  ==>> object of ostream

//cin>>  ==>> object of istream



// ">>" or "<<" we will use when we want to print user defined Data Type
// cout<<object;

//It can't be class member function , you have to make it friend fn of your class

class Test
{
	int x;
public:
	Test(int x = 0):x{x}
	{}

	int start()
	{
		Test t;
		cin >> t;
		cout << t;
		return 0;
	}

	friend istream& operator >> (istream& input, Test& obj);

	friend ostream& operator << (ostream&, Test&);
};


istream& operator >> (istream& input, Test& obj)
{
	input >> obj.x;

	//cin>>obj.x;

	return input;
}

ostream& operator<< (ostream& output, Test& obj)
{
	output << obj.x << endl;
	return output;
}



