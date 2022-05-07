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
#include "TimeOfDay.h"

template<class T, class U>
concept Derived = std::is_base_of<U, T>::value;

template <Derived<SmartSystem> T>
class PowerSchedule
{
private: 
	T* smartSystem;

public:
	// Constructors
	PowerSchedule();
	PowerSchedule(T* system);

	// Mutators
	void setScheduleByDayOfWeek(int dayOfWeek, std::pair<timeOfDay, timeOfDay> startAndEndTime);

	// Methods
	void promptUser();
};
