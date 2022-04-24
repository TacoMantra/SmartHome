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
#include "PowerSchedule.cpp"
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

	// Power schedules
	// TODO: how should these be passed to the instantiated objects?
	PowerSchedule<Lights> livingRoomLightsPowerSchedule;
	PowerSchedule<Television> livingRoomTVPowerSchedule;
	PowerSchedule<Thermostat> hallwayThermostatPowerSchedule;
	PowerSchedule<Security> frontDoorSecurityPowerSchedule;

	return 0;
}