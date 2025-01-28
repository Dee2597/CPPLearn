#pragma once

#include <iostream>

using namespace std;

//Inheritence "IS-A" Relationship
//Types of Inheritence ==> private, public, protected

//1. Single Inheritence

class Vehicle
{
	void Brake()
	{
		cout << "Apply Brake" << endl;
	}
};

class car : public Vehicle
{
	void Tyres()
	{
		cout << "Vehicle has 4 Tyres" << endl;
	}
};


//2. Multilevel Inheritence


class Animal
{

};


class Cat : public Animal
{

};

class RussianBlue : public Cat
{

};   



// We can use "Final" Keyword to non inheritable




