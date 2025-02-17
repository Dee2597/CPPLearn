#pragma once

#include <iostream>

using namespace std;

class Test
{
	int x;
public:

	Test(int x=0):x{x}{}


	//These two function automatically static function
	void* operator new (size_t size)
	{
		cout << "The size of overload operator" << size << endl;
		void* p = malloc(size);
		return p;
	}

	void operator delete(void* p)
	{
		cout << "Deleted" << endl;
		free(p);
	}

};

void* operator new[](size_t size)
{
    cout << "The size of overload operator for Array" << size << endl;
		void* p = malloc(size);
		return p;
	}

	void operator delete[](void* p)
	{
			cout << "Deleted Array" << endl;
			free(p);
	}


void* operator new(size_t size, int val)
	{
			cout << "The size of overload operator with value" << size << endl;
			void* p = malloc(size);
			if (nullptr != p)
			{
				*static_cast<int*>(p) = val;
			}
			return p;
		}

		void operator delete(void* p)
		{
			cout << "Deleted value" << endl;
			free(p);
		}


static int start()
{
	Test* t = new Test();
	delete t;
	

	int* t1 = new int[10];
	delete []t1;

	int* t2 = new(0) int; //Intializing while creating
	delete t2;

	//Due to this we will get control of heap allocation while creating pointer

	return 0;
}

