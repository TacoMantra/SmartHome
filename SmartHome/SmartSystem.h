/**
 * SmartSystem.h
 *
 * Defines base class SmartSystem with base power management
 *
 * Jon Miller, 2022.04.24
 *
 */

#pragma once
#include <string>

class SmartSystem
{
protected:
	std::string name;
	bool isOn = "false";

public:
	// Constructors
	SmartSystem();
	SmartSystem(std::string systemName);

	// Accessors
	std::string getName();
	bool getPowerStatus();

	// Mutators
	void togglePower();
};
