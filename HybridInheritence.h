#pragma once

#include <iostream>

using namespace std;

//combination mutiple and Hirerachical inheritence is Hybrid Inheritence




class Student
{

};

class Male
{

};

class Female
{

};

class Boy : public Student, public Male
{

};

class Girl : public Student, public Female
{

};



int start()
{
	return 0;
}


//Multipath Inheritence  A derived class with two Base class and These class have a one common child class


// is special case of Hybrid Inheritence 

// Memory layout of this will hold 2 human base class ==> to avoid this ambiguity we should use virtual keyword in Base class(Human)


class Human
{
public:
	void work() { cout << "Base class Human" << endl; };
};

class Youtuber : public virtual Human
{


};

class Engineer : public virtual Human
{

	
};

class Deekshi : public virtual Youtuber, public virtual  Engineer
{

};

static int Multipath()
{
	Deekshi d1;
	d1.work();  // Deeksi -> Youtuber --> Human  and Deekshi -->Engineer --> Huma Ambigious  --> it is called Diamond Problem
	// to slolve we need to Inherite Virtually
	return 0;

}