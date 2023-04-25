/*
 * DatastoreModule.c
 *
 *  Created on: Nov 21, 2022
 *      Author: Jeremy Cote
 *
 *  This is the module for storing information.
 */

#include "DataAggregationModule.h"

// ===== Motor Data =====
PRIVATE motor_config_t motorConfig;

PRIVATE motor_status_t motorStatus;

// ===== Motor Config Getters and Setters =====
PUBLIC torque_t SystemGetMaxTorque()
{
	return motorConfig.maxTorque;
}

PUBLIC void SystemSetMaxTorque(torque_t torque)
{
	motorConfig.maxTorque = torque;
}

// ===== Motor Status Getters and Setters =====
PUBLIC flag_status_t SystemGetSPIError()
{
	return motorStatus.spiError;
}

PUBLIC void SystemSetSPIError(flag_status_t status)
{
	motorStatus.spiError = status;
}