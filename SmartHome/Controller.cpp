/**
 * SmartSystem.cpp
 *
 * Implements controller methods for a smart system
 *
 * Jon Miller, 2022.04.30
 *
 */


#include "Controller.h"

Controller::Controller(std::vector<std::string, SmartSystem*> systems)
{
	allSystems = systems;
}

void Controller::selectSystem(SmartSystem* system)
{
	currentSystem = system;
}
