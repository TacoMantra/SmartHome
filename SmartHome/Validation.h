/**
 * Validation.h
 *
 * Defines user prompts to validate input
 *
 * Jon Miller, 2022.04.30
 *
 */

#pragma once
#include <iostream>

using namespace std;

class Validation
{
public:
	void promptForIntegerInRange(int* outputVar, int lower, int upper);
};

