/**
 * SmartSystem.h
 *
 * Defines controller methods for a smart system
 *
 * Jon Miller, 2022.04.30
 *
 */

#pragma once
#include <vector>
#include <map>
#include "SmartSystem.h"

class Controller
{
private:
	SmartSystem* currentSystem;
	std::map<std::string, SmartSystem*> allSystemsDictionary;
	void mapSystem(SmartSystem* system);

public:
	// Constructors
	Controller(std::vector<SmartSystem*> systems);

	// Methods
	void selectSystemByName(std::string name);
};
