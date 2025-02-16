#pragma once


/*
 Inheritance is when one class extends another. So a latte is a drink. 
 Composition is when one class uses or consists of another. So a latte has a flavor shot in it. 
 So a latte doesn't inherit a flavor shot, instead it could be composed with one. This would be another way to represent my drinks.
 I've made a Milk abstract class that Whole and Soy inherits from, and I've made a Flavor class that None, Caramel, and Hazelnut inherit from. This allows me to easily mix and match items as needed.
 And if I want to add almond milk, I don't have to change my Drink classes at all, and this keeps things decoupled.

*/

#include <iostream>



class Entree
{
protected:
	int size;
	char* entree;

	//char entree[10] // if you want make size dynamic go for pointer
public:
	
	Entree(const char* name, int size): size(size)
	{
		entree = new char[size];
		strcpy_s(entree, size-1, name);
	}

	~Entree()
	{
		delete[] entree;
	}

	const char* getEntree()
	{
		return entree;
	}
};

class Drink
{
protected:

	char drink[10];
public:

	Drink(const char* name)
	{
		strncpy_s(drink, name, sizeof(drink) - 1);
	}

	const char* getDrink()
	{
		return drink;
	}

};



class Side
{
protected:
	char side[10];

public:

	Side(const char* name)
	{
		strncpy_s(side, name, sizeof(side) - 1);

	}

	const char* getSide()
	{
		return side;
	}
};


class MealBox
{
private:
	Entree* entree;
	Side* side;
	Drink* drink;
	char bag[100];

public:
	MealBox(const char* type)
	{
		sprintf_s(bag, sizeof(bag), "\n%s meal combo: ", type);
	}

	void setEntree(Entree* e)
	{
		entree = e;
	}

	void setSide(Side* s)
	{
		side = s;
	}

	void setDrink(Drink* d)
	{
		drink = d;
	}

	const char* getMeal()
	{
		sprintf_s(bag, "%s %s, %s, %s", bag, entree->getEntree(), side->getSide(), drink->getDrink());
		return bag;
	}



};


int start()
{
	MealBox mealBox("burger");
	//Entree entree("burger", 10);
	Drink drink("pepsi");
	Side side("fries");

	mealBox.setEntree(new Entree("burger", 10));
	mealBox.setDrink(&drink);
	mealBox.setSide(&side);

	std::cout<< mealBox.getMeal()<<std::endl;

	return 0;

}