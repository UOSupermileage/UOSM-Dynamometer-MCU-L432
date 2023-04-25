/*
 * DatastoreModule.h
 *
 *  Created on: Nov 21, 2022
 *      Author: Jeremy Cote
 */

#ifndef MODULES_DATAAGGREGATIONMODULE_H_
#define MODULES_DATAAGGREGATIONMODULE_H_

#include <ApplicationTypes.h>

typedef struct
{
	torque_t maxTorque;
} motor_config_t;

typedef union
{
	uint32_t all;
	struct
	{
		uint32_t spiError : 1;
		uint32_t reserved;
	};
} motor_status_t;

void InitDataAggregator();

PUBLIC torque_t SystemGetMaxTorque();

PUBLIC void SystemSetMaxTorque(torque_t torque);

PUBLIC flag_status_t SystemGetSPIError();

PUBLIC void SystemSetSPIError(flag_status_t status);

#endif /* MODULES_DATAAGGREGATIONMODULE_H_ */
