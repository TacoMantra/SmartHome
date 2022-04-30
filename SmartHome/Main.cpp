/**
 * Main.cpp
 *
 * Instantiates Lights, Television, Thermostat, and Security
 * objects.
 * 
 * Jon Miller, 2022.04.24
 *
 */

#include <iostream>
#include <vector>
#include "PowerSchedule.cpp"
#include "SmartSystem.h"
#include "Controller.h"
#include "Lights.h"
#include "Television.h"
#include "Thermostat.h"
#include "Security.h"
#include "Validation.h"

int main()
{
	// Systems
	Lights livingRoomLights("Living Room Lights");
	Television livingRoomTV("Living Room TV");
	Thermostat hallwayThermostat("Hallway Thermostat");
	Security frontDoorSecurity("Front Door Security Alarm");

	std::vector<SmartSystem*> allSystems {
		&livingRoomLights,
		&livingRoomTV,
		&hallwayThermostat,
		&frontDoorSecurity
	};

	// Controller
	Controller controller(allSystems);

	// Validation
	Validation validation;

	// Power schedules
	// TODO: how should these be passed to the instantiated objects?
	PowerSchedule<Lights> livingRoomLightsPowerSchedule;
	PowerSchedule<Television> livingRoomTVPowerSchedule;
	PowerSchedule<Thermostat> hallwayThermostatPowerSchedule;
	PowerSchedule<Security> frontDoorSecurityPowerSchedule;
	
	// Choose a system
	int systemChoice;
	std::cout << "Choose a system:" << std::endl;
	for (int i = 0; i < allSystems.size(); i++)
	{
		std::cout << i+1 << ": " << allSystems[i]->getName() << std::endl;
	}
	validation.promptForIntegerInRange(&systemChoice, 1, allSystems.size());

	controller.selectSystemByName(allSystems[systemChoice - 1]->getName());
	SmartSystem currentSystem = controller.getCurrentSystem();
	std::string currentSystemName = currentSystem.getName();


	// Perform an action
	int actionChoice;
	std::cout << "What would you like to do?" << std::endl << "1. Turn " << currentSystemName << (currentSystem.getPowerStatus() ? " off" : " on") << std::endl;
	validation.promptForIntegerInRange(&actionChoice, 1, 1);

	switch (actionChoice)
	{
	case 1:
		currentSystem.togglePower();
		std::cout << currentSystemName << " system is " << (currentSystem.getPowerStatus() ? "on" : "off") << std::endl;
		break;
	// TODO: more actions based on type of system chosen
	default:
		cout << "Some other action..." << std::endl;
	}
	// TODO: extract to function, recurse back to main menu

	return 0;
}