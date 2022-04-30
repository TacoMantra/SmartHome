/**
 * Validation.h
 *
 * Implements user prompts to validate input for different
 * numeric types.
 *
 * Jon Miller, 2022.04.15
 *
 */

#include <iostream>
#include "Validation.h"

using namespace std;

void Validation::promptForIntegerInRange(int* outputVar, int lower, int upper)
{
	bool valid = false;

	do
	{
		cin >> *outputVar;

		if (cin.good() && *outputVar >= lower && *outputVar <= upper)
		{
			valid = true;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a number between " << lower << " and " << upper << endl;
		}
	} while (!valid);
}