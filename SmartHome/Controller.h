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
#include "SmartSystem.h";

class Controller
{
private:
	SmartSystem* currentSystem;
	std::vector<std::string, SmartSystem*> allSystems;

public:
	// Constructors
	Controller(std::vector<std::string, SmartSystem*> systems);

	// Methods
	void selectSystem(SmartSystem* system);
};
