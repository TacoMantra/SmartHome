/**
 * Thermostat.cpp
 *
 * Implements Thermostat class, which implements base class
 * SmartSystem and introduces daytime/nighttime temperature
 * schedule.
 *
 * Jon Miller, 2022.04.24
 *
 */

#include "Thermostat.h"
#include <map>
#include <iostream>

int Thermostat::getCurrentTemperature()
{
    return currentTemperature;
}

std::map<DaysOfWeek, DailyTemperatureSchedule> Thermostat::getWeeklyTemperatureSchedule()
{
    return weeklyTemperatureSchedule;
}

void Thermostat::setCurrentTemperature(int temperature)
{
    currentTemperature = temperature;
}

void Thermostat::setTemperatureScheduleByDayOfWeek(DaysOfWeek day, DailyTemperatureSchedule schedule)
{
    weeklyTemperatureSchedule[day] = schedule;
}

void Thermostat::runSchedule()
{
    // TODO: implement running process
    std::cout << "Schedule is running";
}
