#pragma once
#include <iostream>
#include <string>

using namespace std;



class Entree
{
protected:
	string entree;

public:
	string getEntree()
	{
		return entree;
	}
};

class Burger :public Entree
{
public:
	Burger()
	{
		entree = "burger";
	}


};

class HotDog : public Entree
{
public:
	HotDog()
	{
		entree = "hotdog";
	}
};


class Side
{
protected:
	string side;
public:
	string getSide()
	{
		return side;
	}

};

class Fries : public Side
{
public:
	Fries()
	{
		side = "fries";
	}
};

class Salad : public Side
{
public:
	Salad()
	{
		side = "salad";
	}

};


class Drink
{
public:
	string drink;

public:
	Drink()
	{
		drink = "pepsi";
	}

	string getDrink()
	{
		return drink;
	}
};


class MealCombo
{

	Entree* e;
	Side* s;
	Drink* d;

	string bag;

public:
	MealCombo(string type)
	{
		bag = type + "meal combo: ";
	}

	void setEntree(Entree* entree)
	{
		e = entree;
	}

	void setDrink(Drink* drink)
	{
		d = drink;
	}

	void setSide(Side* side)
	{
		s = side;
	}

	string openMealBox()
	{
		bag = bag + e->getEntree() + ", " + s->getSide() + ", " + d->getDrink();
		return bag;
	}


};

class MealBuilder
{
protected:
	MealCombo* meal;

public:
	virtual void cookEntree() {};
	virtual void cookSide() {};
	virtual void fillDrink() {};

	MealCombo* getmeal()
	{
		return meal;
	}
};

class BurgerMealBuilder : public MealBuilder
{
public:

	BurgerMealBuilder()
	{
		meal = new MealCombo("Burger");
	}

	void cookEntree()override
	{
		Entree* entree = new Burger();
		meal->setEntree(entree);
	}

	void cookSide()override
	{
		Side* side = new Fries();
		meal->setSide(side);
	}

	void fillDrink()override
	{
		Drink* drink = new Drink();
		meal->setDrink(drink);
	}

};

class HotDogMealBuilder : public MealBuilder
{
public:

	HotDogMealBuilder()
	{
		meal = new MealCombo("HotDog");
	}

	void cookEntree()
	{
		Entree* entree = new HotDog();
		meal->setEntree(entree);
	}

	void cookSide()
	{
		Side* side = new Salad();
		meal->setSide(side);
	}

	void fillDrink()
	{
		Drink* drink = new Drink();
		meal->setDrink(drink);
	}

};


int start()
{
	cout << "Please choose what do want to have" << endl;

	cout << "Select 1 for Burger Meal and 2 for HotDog Meal" << endl;

	int  input;

	MealBuilder* builder{};

	cin >> input;

	switch (input)
	{
	case 1:
		builder = new BurgerMealBuilder();
		break;

	case 2:
		builder = new HotDogMealBuilder();
		break;

	default:
		cout << "Invalid option";
	}

	builder->cookEntree();
	builder->cookSide();
	builder->fillDrink();

	cout<< builder->getmeal()->openMealBox()<<endl;

	

	


}


