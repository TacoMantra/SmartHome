/**
 * Television.cpp
 *
 * Implements Television class, which implements base class
 * SmartSystem and introduces channel management.
 *
 * Jon Miller, 2022.04.24
 *
 */

#include "Television.h"

int Television::getCurrentChannel()
{
    return currentChannel;
}

void Television::setCurrentChannel(int channel)
{
    currentChannel = channel;
}

