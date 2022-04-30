/**
 * SmartSystem.cpp
 *
 * Implements controller methods for a smart system
 *
 * Jon Miller, 2022.04.30
 *
 */


#include "Controller.h"
#include <iostream>
#include<algorithm>

void Controller::mapSystem(SmartSystem* system)
{
	allSystemsDictionary.insert(std::pair<std::string, SmartSystem*>(system->getName(), system));
}

Controller::Controller(std::vector<SmartSystem*> systems)
{
	for (int i = 0; i < systems.size(); i++)
	{
		mapSystem(systems[i]);
	}

	currentSystem = allSystemsDictionary[0];
}

void Controller::selectSystemByName(std::string name)
{
	currentSystem = allSystemsDictionary[name];
}
