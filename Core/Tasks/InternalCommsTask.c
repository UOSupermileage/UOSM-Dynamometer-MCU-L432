/*
 * InternalCommsTask.c
 *
 *  Created on: Sep 10, 2022
 *      Author: mingy
 */

// #include "CANMessageLookUpModule.h"
#include "InternalCommsTask.h"
#include "InternalCommsModule.h"
#include "CANMessageLookUpModule.h"
#include "SerialDebugDriver.h"
#include "Profiles.h"
#include "DataAggregationModule.h"

// Function alias - replace with the driver api
#define DebugPrint(...) SerialPrintln(__VA_ARGS__)

#define STACK_SIZE 128 * 8
#define INTERNAL_COMMS_TASK_PRIORITY (osPriority_t) osPriorityRealtime3
#define TIMER_INTERNAL_COMMS_TASK 100UL

#define THROTTLE_ERROR_BROADCAST_RATE 5
#define DEADMAN_BROADCAST_RATE 2

PUBLIC void InitInternalCommsTask(void);
PRIVATE void InternalCommsTask(void *argument);

const char ICT_TAG[] = "#ICT:";

osThreadId_t InternalCommsTaskHandle;
const osThreadAttr_t InternalCommsTask_attributes = {
	.name = "InternalCommunications",
	.stack_size = STACK_SIZE,
	.priority = INTERNAL_COMMS_TASK_PRIORITY,
};

PUBLIC void InitInternalCommsTask(void)
{
#ifdef PROFILE_ICOMMS
	InternalCommsTaskHandle = osThreadNew(InternalCommsTask, NULL, &InternalCommsTask_attributes);
#endif
}
PRIVATE void InternalCommsTask(void *argument)
{
	uint32_t cycleTick = osKernelGetTickCount();
	DebugPrint("%s icomms", ICT_TAG);

	const ICommsMessageInfo *errorInfo = CANMessageLookUpGetInfo(ERROR_DATA_ID);
	const ICommsMessageInfo *eventInfo = CANMessageLookUpGetInfo(EVENT_DATA_ID);

	uint8_t throttleErrorBroadcastCounter = 0;
	uint8_t deadmanBroadcastCounter = 0;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);

	for (;;)
	{
		cycleTick += TIMER_INTERNAL_COMMS_TASK;
		osDelayUntil(cycleTick);

		IComms_PeriodicReceive();
	}
}
