#pragma once

// HAS -A  : Composition is HAS-A Relation   --> 2 types  1) composition and Aggregation
// IS -A : Inheritence is "IS_A" Relation


#include <iostream>

using namespace std;

class Tire
{

};

class Engine
{

};

/*
Here Tyre or Enginee is Composition of vehicle

Vehical shouls have Enginee or Tyre
*/

class Vehicle
{
	Tire t1;
	Engine e1;
};

class Car : public Vehicle
{

};