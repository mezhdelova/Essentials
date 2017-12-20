#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Engine
{
public:
	void PrintInfo(string volume)
	{
		cout << "Engine: " << volume << endl;
	}
};

class Wheels
{
public:
	void PrintInfo(string info)
	{
		for (int i = 0; i < 4; i++)
			cout << "Wheel: " << info << endl;
	}

};

class Chassis
{
public:
	void PrintInfo(string info)
	{
		cout << "Chassis: " << info << endl;
	}
};

class Lights
{
public:
	void PrintInfo(string type)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "Light: " << type << endl;
		}
	}
};

class Body
{
public:
	void PrintInfo(string color)
	{
		cout << "Body: " << color << endl;
	}
};

	class Car
{
private:
	Engine carEngine;
	Wheels carWhells;
	Chassis carChassis;
	Lights carLights;
	Body carBody;

public:
	void PrintInfo()
	{
		carEngine.PrintInfo("1.0");
		carWhells.PrintInfo("16inches");
		carChassis.PrintInfo("Normal");
		carLights.PrintInfo("Type 1");
		carLights.PrintInfo("Type 2");
		carLights.PrintInfo("Type 3");
		carLights.PrintInfo("Type 4");
		carLights.PrintInfo("Type 5");
		carBody.PrintInfo("Black");
	}
};

		int main(void) {

			Car myCar;
			myCar.PrintInfo();

			return 0;
		}
