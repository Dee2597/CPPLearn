#pragma once

#include <iostream>

using namespace std;

class Youtuber
{
	int x;
public:
	Youtuber(int x): x{x}
	{
		cout << "Youtuber" << endl;
	}

	void work()
	{
		cout << "Working on Youtube" << endl;
	}

};

class Enginer
{
	int y;
public:
	Enginer(int y) : y{ y } { cout << "Engineer" << endl; }

	void work()
	{
		cout << "Working as Engineer" << endl;
	}

};

//Deekshi "IS A" Youtuber

//Deekshi "IS A" Enginer

//constructor order depend upons inheritance

//Here ==> Enginer ==>Youtuber ==>Deekshi   and Destructor is Exactly opposite

class Deekshi : public Enginer, public Youtuber
{
public:
	Deekshi(int x, int y) : Youtuber(x), Enginer(y)
	{
		cout << "Deekshi" << endl;
	}
};



int start()
{
	Deekshi r1(1, 2);
	//r1.work();  // it will throw error because don't know which function need to call

//solution:

	r1.Youtuber::work();

	Enginer de = r1;
	de.work();

	static_cast<Enginer>(r1).work();
}
