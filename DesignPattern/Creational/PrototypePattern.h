#pragma once
#include <iostream>
#include <cstring> // Include for strcpy

using namespace std;

class Animal
{
protected:
    char hairColor[10];
    int hairLength, tail, weight, height, age;
    int intelligence, stubbornness, aggressiveness;

public:


    virtual Animal* clone() = 0;


    // Setter for hairColor
    void setHairColor(const char* color) {
        strncpy(hairColor, color, sizeof(hairColor) - 1);
        hairColor[sizeof(hairColor) - 1] = '\0'; // Ensure null-termination
    }

    // Setter for hairLength
    void setHairLength(int length) {
        hairLength = length;
    }

    // Setter for tail
    void setTail(int t) {
        tail = t;
    }

    // Setter for weight
    void setWeight(int w) {
        weight = w;
    }

    // Setter for height
    void setHeight(int h) {
        height = h;
    }

    // Setter for age
    void setAge(int a) {
        age = a;
    }

    // Setter for intelligence
    void setIntelligence(int i) {
        intelligence = i;
    }

    // Setter for stubbornness
    void setStubbornness(int s) {
        stubbornness = s;
    }

    // Setter for aggressiveness
    void setAggressiveness(int a) {
        aggressiveness = a;
    }
};


class Sheep : public Animal
{

public:

    Sheep()
    {
        hairLength = 5;
        intelligence = 7;
    }

    Animal* clone()
    {
        return new Sheep(*this); // it will call copy constructor --- > Sheep(const Sheep& other){}

        //it will do shallow copy default copy constructor if we need deep copy we need to write customized copy constructor
        
    }

   
};


class Cow : public Animal
{

public:

    Cow()
    {
        stubbornness = 6;
        intelligence = 8;
    }

    Animal* clone()
    {
        return new Cow(*this);
    }

};


int start()
{
    Sheep* sheep0 = new Sheep();
    sheep0->setAge(45);
    sheep0->setHairColor("white");


    Cow* cow0 = new Cow();
    cow0->setHairColor("black");
    cow0->setAge(12);

    Animal* Farm[3];

    Farm[0] = sheep0->clone();

    Farm[1] = cow0->clone();

    Farm[2] = sheep0->clone();

    Farm[2]->setHairLength(5);

}



