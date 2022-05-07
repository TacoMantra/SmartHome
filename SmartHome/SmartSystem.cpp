/**
 * SmartSystem.cpp
 *
 * Implements base class SmartSystem with base power management
 *
 * Jon Miller, 2022.04.24
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>  
#include "SmartSystem.h"

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
	// Get the current day of week
	time_t rawtime;
	tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	int wday = timeinfo->tm_wday;
	int currentHour = timeinfo->tm_hour;
	int currentMinute = timeinfo->tm_min;
	std::pair<timeOfDay, timeOfDay> todaySchedule = weeklySchedule[wday];

	// If user has overridden the power schedule or if there's no schedule for today, return the user overridden power status
	if (powerScheduleIsOverridden || weeklySchedule.find(wday) == weeklySchedule.end())
	{
		return overridePowerIsOn;
	}

	// Otherwise check if the current time is between the scheduled start and end times for today
	return (
		currentHour > todaySchedule.first.hour &&
		currentMinute > todaySchedule.first.minute &&
		currentHour < todaySchedule.second.hour&&
		currentMinute < todaySchedule.second.minute
	);
}

void SmartSystem::toggleOverridePower()
{
	overridePowerIsOn = !overridePowerIsOn;
	if (!powerScheduleIsOverridden)
	{
		powerScheduleIsOverridden = true;
	}
}

void SmartSystem::updateWeeklySchedule(int dayOfWeek, std::pair<timeOfDay, timeOfDay> startAndEndTime)
{
	weeklySchedule[dayOfWeek] = startAndEndTime;
}
