#pragma once

//Frnd Function

class Base
{
	int x;
public:
	Base() {}

	Base(int a):x{a}{}

	friend void set(Base&, int);

	friend class child;

};

//we should keep Base above child to compiler knows

//Friend ship is not mutual : here Child is friend of Base,  Base is not a friend child


// friend fn can not be inherited -- only for which class friend is written


class child
{
public:
	void setBasePrivate(Base& obj, int val)
	{
		obj.x = val;
	}
};

void set(Base& obj, int x)
{
	obj.x = x;
}

int start()
{
	Base obj;
	set(obj, 10);

	child obj1;
	obj1.setBasePrivate(obj, 20);
}