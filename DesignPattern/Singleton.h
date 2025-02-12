#pragma once

#include <iostream>

using namespace std;

class Singleton
{
	Singleton()
	{
		cout << "Singleton Object created" << endl;
	}

	static Singleton* m_singletonObj;


public:

	static Singleton* getInstance()
	{
		if (nullptr == m_singletonObj)
		{
			m_singletonObj = new Singleton();
			
		}
		else
		{
			cout << "Object cannot be created" << endl;
		}

		return m_singletonObj;
	}

	
};


Singleton* Singleton::m_singletonObj = NULL;


int start()
{
	Singleton::getInstance();

	Singleton::getInstance();

	return 0;


}


/*

It is not a thread safe

It is inflexible and it is inextensiable

*/