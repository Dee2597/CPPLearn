#pragma once

#include <iostream>
#include <string>

using namespace std;


class Door
{
protected:
	string m_sound;
public:

	void open()
	{
		std::cout << "The door sound is: " << m_sound << std::endl;
	}



};

class GasolineCarDoor : public Door
{
public:

	GasolineCarDoor()
	{
		std::cout << "Gasoline car Door Created" << std::endl;
		m_sound = "Grrrr";
	}
};

class ElectricCarDoor : public Door
{

public:
	ElectricCarDoor()
	{
		std::cout << "Electric car Door Created" << std::endl;
		m_sound = "shhhhhh";
	}

};



class Engine
{
protected:
	std::string m_engineSound;

public:

	void Run()
	{
		std::cout << "The Enginee sound is: " << m_engineSound << endl;
	}
};

class GasolineCarEngine : public Engine
{
public:
	GasolineCarEngine()
	{
		std::cout << "The Gasoline car Enginee is created" << std::endl;
		m_engineSound = "reevvvvvvvvvv";
	}

};

class ElectricCarEngine : public Engine
{
public:
	ElectricCarEngine()
	{
		std::cout << "The Electric car Enginee is created" << endl;
		m_engineSound = "suuuuuuu";
	}
};


class CarFactory
{
public:
	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

class GasolineCarFactory : public CarFactory
{
public:

	//GasolineCarFactory() = default;

	Door* BuildDoor() 
	{
		return new GasolineCarDoor();
	}

	Engine* BuildEngine()
	{
		return new GasolineCarEngine();
	}
};

class ElectricCarFactory : public CarFactory
{

public: 
	//ElectricCarFactory() = default;

	Door* BuildDoor()
	{
		return new ElectricCarDoor();
	}

	Engine* BuildEngine()
	{
		return new ElectricCarEngine();
	}
};


int start()
{
	CarFactory* carPlant;
	int chioce;

	cout << "enter car choice:" << endl;
	cout << "Select 1. Gasoline or 2. Electric" << endl;

	cin >> chioce;

	switch (chioce)
	{
	case 1: 
		carPlant = new GasolineCarFactory;
		break;

	case 2:
		carPlant = new ElectricCarFactory;
		break;
	default:
		cout << "Invalid selection" << endl;
		carPlant = NULL;
		break;
	}


	if (nullptr != carPlant)
	{
		Door* door = carPlant->BuildDoor();
		Engine* engine = carPlant->BuildEngine();

		if (nullptr != door)
		{
			door->open();
		}

		if (nullptr != engine)
		{
			engine->Run();
		}
	}

	return 0;

}




