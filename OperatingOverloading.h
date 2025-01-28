#pragma once
#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;

public:

	Point (){}
	Point(int x, int y) : x{ x }, y{ y }
	{

	}

	Point operator +(const Point& rhs)
	{
		Point p;
		p.x = rhs.x;
		p.y = rhs.y;
		return p;
	}

	Point operator -(const Point& rhs)
	{
		Point p;
		p.x = rhs.x;
		p.y = rhs.y;
		return p;
	}

	Point Add(const Point& rhs)
	{
		Point p;
		p.x = rhs.x;
		p.y = rhs.y;
		return p;
	}

	//Unary Operator Overloading
	Point operator -()
	{
		return Point(-x, -y);
	}


};


int start()
{
	Point p1 = Point(1, 2);
	Point p2 = Point(4, 3);
	Point p3 = p1 + p2;
	Point p4 = p1 - p2;

	Point p5 = p1.Add(p2);

	//Unary Operator Overloading

	Point p6 = - p1;
}

//Few Operator we can't overload

// ::  ==> ?:  ==> . ==> .* ==> sizeof



//Array Subscript [] operator Overload

class Points
{
	int arr[2];
public:
	Points(int x, int y)
	{
		arr[0] = x;
		arr[1] = y;
	}

	int& operator [](int x)
	{
		if (x == 0)
		{
			return arr[0];
		}
		else if (x == 1)
		{
			return arr[1];
		}
		else
		{
			cout << "out of bound" << endl;
		}
	}
};

int startMain()
{
	Points p1(1, 3);
	p1[0] = 2;
}


