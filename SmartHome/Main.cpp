/**
 * Main.cpp
 *
 * Instantiates Lights, Television, Thermostat, and Security
 * objects and guides user through basic operations.
 * 
 * Jon Miller, 2022.04.30
 *
 */

#include <iostream>
#include <vector>
#include <map>
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

	// Power schedules
	PowerSchedule<SmartSystem> livingRoomLightsPowerSchedule(&livingRoomLights);
	PowerSchedule<SmartSystem> livingRoomTVPowerSchedule(&livingRoomTV);
	PowerSchedule<SmartSystem> hallwayThermostatPowerSchedule(&hallwayThermostat);
	PowerSchedule<SmartSystem> frontDoorSecurityPowerSchedule(&frontDoorSecurity);

	std::vector<PowerSchedule<SmartSystem>> allSchedules
	{
		livingRoomLightsPowerSchedule,
		livingRoomTVPowerSchedule,
		hallwayThermostatPowerSchedule,
		frontDoorSecurityPowerSchedule
	};

	std::map<string, PowerSchedule<SmartSystem>> schedulesDictionary;

	for (int i = 0; i < allSystems.size(); i++)
	{
		schedulesDictionary.insert({ allSystems[i]->getName(), allSchedules[i] });
	};

	// Controller
	Controller controller(allSystems);

	// Validation
	Validation validation;
	
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
	// TODO: more actions based on type of system chosen
	std::cout << "What would you like to do?" << std::endl
		<< "1. Turn " << currentSystemName << (currentSystem.getPowerStatus() ? " off" : " on") << std::endl
		<< "2. Set a power schedule for " << currentSystemName << std::endl;

	validation.promptForIntegerInRange(&actionChoice, 1, 2);

	switch (actionChoice)
	{
	case 1:
		currentSystem.toggleOverridePower();
		std::cout << currentSystemName << " system is " << (currentSystem.getPowerStatus() ? "on" : "off") << std::endl;
		break;
	case 2:
		schedulesDictionary[currentSystemName].promptUser();
		break;
	default:
		cout << "Some other action..." << std::endl;
	}

	return 0;
}