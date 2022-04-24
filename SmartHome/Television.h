/**
 * Television.h
 *
 * Defines Television class, which implements base class
 * SmartSystem and introduces channel management.
 *
 * Jon Miller, 2022.04.24
 *
 */

#pragma once
#include "SmartSystem.h"
class Television :
    public SmartSystem
{
private:
    int currentChannel;

public:
    // Constructors
    using SmartSystem::SmartSystem;

    // Accessors
    int getCurrentChannel();

    // Mutators
    void setCurrentChannel(int channel);
};
