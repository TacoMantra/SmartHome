/**
 * PowerSchedule.cpp
 *
 * Implements generic power schedule for objects extending
 * base class SmartSystem
 *
 * Jon Miller, 2022.04.24
 *
 */

#include "PowerSchedule.h";

template<Derived<SmartSystem> T>
inline std::map<DaysOfWeek, std::pair<tm, tm>> PowerSchedule<T>::getWeeklySchedule()
{
	return weeklySchedule;
}

template<Derived<SmartSystem> T>
inline void PowerSchedule<T>::setScheduleByDayOfWeek(DaysOfWeek day, std::pair<tm, tm> startAndEndTime)
{
	weeklySchedule[day] = startAndEndTime;
}

template<Derived<SmartSystem> T>
inline void PowerSchedule<T>::runSchedule()
{
	std::cout << "Power schedule is running";
}
