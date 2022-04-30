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

	// Power schedules
	// TODO: how should these be passed to the instantiated objects?
	PowerSchedule<Lights> livingRoomLightsPowerSchedule;
	PowerSchedule<Television> livingRoomTVPowerSchedule;
	PowerSchedule<Thermostat> hallwayThermostatPowerSchedule;
	PowerSchedule<Security> frontDoorSecurityPowerSchedule;
	
	std::cout << "Choose a system:" << std::endl;

	return 0;
}