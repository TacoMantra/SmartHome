/**
 * SmartSystem.cpp
 *
 * Implements base class SmartSystem with base power management
 *
 * Jon Miller, 2022.04.24
 *
 */

#include "SmartSystem.h"
#include <string>

SmartSystem::SmartSystem()
{
}

SmartSystem::SmartSystem(std::string systemName)
{
	name = systemName;
}

std::string SmartSystem::getName()
{
	return name;
}

bool SmartSystem::getPowerStatus()
{
	return isOn;
}

void SmartSystem::togglePower()
{
	isOn = !isOn;
}
