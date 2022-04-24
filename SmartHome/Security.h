/**
 * Security.h
 *
 * Defines Security class, which implements base class
 * SmartSystem and introduces sensitivity management.
 *
 * Jon Miller, 2022.04.24
 *
 */

#pragma once
#include "SmartSystem.h"
class Security :
    public SmartSystem
{
private:
    int sensitivity;

public:
    // Constructors
    using SmartSystem::SmartSystem;

    // Accessors
    int getSensitivity();

    // Mutators
    void setSensitivity(int sensitivityOneToFive);
};
