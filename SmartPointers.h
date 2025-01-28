#pragma once


/*
* 
* Smarrt Pointer is a class which wraps a raw pointer to manage the life time of the pointer

Types of Smart Pointer:

1. Unique Pointer: Allows only one owner of the underlying pointer

2. Shared_ptr: Allows multiple owners of the same pointer(Ref count is maintained)

3. weak_ptr:  it is special type of shared ptr it doesn't count the reference



*/


#include <iostream>

using namespace std;

class MyInt
{
public:
	explicit MyInt(int* p = nullptr) { data = p; }
	~MyInt() { delete data; }

	int& operator *() { return *data; }

private:
	int* data;
};


int start()
{
	int* p = new int(10);
	MyInt myint = MyInt(p);
	cout << *myint << endl;
	return 0;

}