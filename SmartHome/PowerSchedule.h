/**
 * PowerSchedule.h
 *
 * Defines generic power schedule for objects extending
 * base class SmartSystem
 *
 * Jon Miller, 2022.04.24
 *
 */

#pragma once
#include <iostream>
#include <concepts>
#include <map>
#include "SmartSystem.h"
#include "DaysOfWeek.h"

template<class T, class U>
concept Derived = std::is_base_of<U, T>::value;

template <Derived<SmartSystem> T>
class PowerSchedule
{
private:
	std::map<DaysOfWeek, std::pair<tm, tm>> weeklySchedule;

public:
	// Accessors
	std::map<DaysOfWeek, std::pair<tm, tm>> getWeeklySchedule();

	// Mutators
	void setScheduleByDayOfWeek(DaysOfWeek day, std::pair<tm, tm> startAndEndTime);

	// Methods
	void runSchedule();
};
