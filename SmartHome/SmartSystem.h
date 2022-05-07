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
#include <map>
#include "TimeOfDay.h"
#include "PowerSchedule.h"

class SmartSystem
{
protected:
	std::string name;
	bool powerScheduleIsOverridden = false;
	bool overridePowerIsOn = false;
	std::map<int, std::pair<timeOfDay, timeOfDay>> weeklySchedule;

public:
	// Constructors
	SmartSystem();
	SmartSystem(std::string systemName);

	// Accessors
	std::string getName();
	bool getPowerStatus();

	// Mutators
	void toggleOverridePower();
	void updateWeeklySchedule(int dayOfWeek, std::pair<timeOfDay, timeOfDay> startAndEndTime);
};
