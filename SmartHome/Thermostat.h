/**
 * Thermostat.h
 *
 * Defines Thermostat class, which implements base class
 * SmartSystem and introduces daytime/nighttime temperature
 * schedule.
 *
 * Jon Miller, 2022.04.24
 *
 */

#pragma once
#include <map>
#include "SmartSystem.h"
#include "DaysOfWeek.h"

struct DailyTemperatureSchedule
{
    int dayTemp;
    int nightTemp;
};
class Thermostat :
    public SmartSystem
{
private:
    int currentTemperature;
    std::map<DaysOfWeek, DailyTemperatureSchedule> weeklyTemperatureSchedule;

public:
    // Constructors
    using SmartSystem::SmartSystem;

    // Accessors
    int getCurrentTemperature();
    std::map<DaysOfWeek, DailyTemperatureSchedule> getWeeklyTemperatureSchedule();

    // Mutators
    void setCurrentTemperature(int temperature);
    void setTemperatureScheduleByDayOfWeek(DaysOfWeek day, DailyTemperatureSchedule schedule);

    // Methods
    void runSchedule();
};

