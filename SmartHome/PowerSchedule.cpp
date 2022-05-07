/**
 * PowerSchedule.cpp
 *
 * Implements generic power schedule for objects extending
 * base class SmartSystem
 *
 * Jon Miller, 2022.04.24
 *
 */

#include <chrono>
#include <ctime>
#include <map>
#include "PowerSchedule.h"
#include "TimeOfDay.h"
#include "Validation.h"

template<Derived<SmartSystem> T>
PowerSchedule<T>::PowerSchedule()
{
}

template<Derived<SmartSystem> T>
inline PowerSchedule<T>::PowerSchedule(T* system)
{
    smartSystem = system;
}

template<Derived<SmartSystem> T>
inline void PowerSchedule<T>::setScheduleByDayOfWeek(int dayOfWeek, std::pair<timeOfDay, timeOfDay> startAndEndTime)
{
    if (dayOfWeek < 1 || dayOfWeek > 7)
    {
        throw std::out_of_range("Parameter is outside of range 1-7");
    }

    smartSystem->updateWeeklySchedule(dayOfWeek, startAndEndTime);
}

template<Derived<SmartSystem> T>
inline void PowerSchedule<T>::promptUser()
{
    Validation validation;
    std::string daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    int dayChoice, startHour, startMinute, endHour, endMinute, shouldContinue;

    std::cout << "Choose a day" << std::endl;

    for (int i = 0; i < 7; i++)
    {
        std::cout << std::endl << i + 1 << ": " << daysOfWeek[i] << ":" << std::endl;
    }
    validation.promptForIntegerInRange(&dayChoice, 1, 7);

    std::cout << daysOfWeek[dayChoice - 1] << std::endl << std::endl << "Enter the Hours and Minutes to Turn Power On:" << std::endl << "Hours:" << std::endl;
    validation.promptForIntegerInRange(&startHour, 1, 24);
    std::cout << "Minutes:" << std::endl;
    validation.promptForIntegerInRange(&startMinute, 1, 60);

    std::cout << daysOfWeek[dayChoice - 1] << std::endl << std::endl << "Enter the Hours and Minutes to Turn Power Off:" << std::endl << "Hours:" << std::endl;
    validation.promptForIntegerInRange(&endHour, 1, 24);
    std::cout << "Minutes:" << std::endl;
    validation.promptForIntegerInRange(&endMinute, 1, 60);

    timeOfDay startTime = {
        startHour,
        startMinute
    };
    timeOfDay endTime = {
        endHour,
        endMinute
    };
    std::pair<timeOfDay, timeOfDay> startAndEndTimes = {
        startTime,
        endTime
    };

    try
    {
        setScheduleByDayOfWeek(dayChoice - 1, startAndEndTimes);
    }
    catch (int e)
    {
        cout << "Sorry, unable to set schedule..." << e << std::endl;
    }

    std::cout << "Add another day?" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
    validation.promptForIntegerInRange(&shouldContinue, 1, 2);

    if (shouldContinue == 1)
    {
        promptUser();
    }
}
