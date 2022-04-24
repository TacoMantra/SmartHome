/**
 * Security.cpp
 *
 * Implements Security class, which implements base class
 * SmartSystem and introduces sensitivity management.
 *
 * Jon Miller, 2022.04.24
 *
 */


#include <stdexcept>
#include "Security.h"

int Security::getSensitivity()
{
    return sensitivity;
}

void Security::setSensitivity(int sensitivityOneToFive)
{
    if (sensitivityOneToFive < 1 || sensitivityOneToFive > 5)
    {
        throw std::out_of_range("Parameter is outside of range 1-5");
    }
    sensitivity = sensitivityOneToFive;
}
