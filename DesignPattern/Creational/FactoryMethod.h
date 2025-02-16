#pragma once
#include <iostream>
#include <string>

using namespace std;

/*
You can think of the product and concrete product as defining how the factory creates an object.
And the concrete creator defines what to create.
If I want to add another item to the coffee machine, such as an Americano, I only need to define a new concrete product for it and extend the concrete creator to include it. 
The key here is that the factory method pattern lets the subclasses instantiate the object- instead of the main program.
This allows a programmer to easily add new products or change existing ones without needing to make changes throughout an entire code base.
*/


class Coffee
{
protected:
	string type;

public:

	Coffee()
	{

	}

	string getType()
	{
		return type;
	}


};

class Espresso : public Coffee
{
public:
	Espresso() : Coffee()
	{
		type = "Espresso";
	}
};

class Latte : public Coffee
{
public:

	Latte() : Coffee()
	{
		type = "Latte";
	}

};


class CoffeMakeFactory
{
public:

	Coffee* GetCoffee()
	{
		int choice;

		cout << "Select type of coffee to make: " << endl;
		cout << "1: Espresso,  2:Latte" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			return new Espresso();
		case 2:
			return new Latte();

		default:
			cout << "Invalid selection" << endl;
			return NULL;

		}
	}
};


int start()
{
	CoffeMakeFactory CoffeFactory;

	Coffee* cup;
	cup = CoffeFactory.GetCoffee();

	cout << "The selected coffee type is: " << cup->getType() << endl;
}

