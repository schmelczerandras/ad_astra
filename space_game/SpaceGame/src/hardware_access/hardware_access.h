#ifndef HARDWARE_ACCESS_H
#define HARDWARE_ACCESS_H

#include <stdbool.h>
#include <avr/io.h>
#include "bitwise.h"

#include "power_saving/power_saving.h"
#include "spi/spi.h"
#include "timing/timing.h"

#include "output_pins/output_pins.h"


/*
	This module contains the lowest level functions to manipulate the hardware.
	You only have to include this header file which serves as a facade.
	The sub-modules' implementation can be freely changed as long as they
	still implement these functions.
*/

// Initialize every hardware element at once
void initializeHardwareAccess();

// Enable interrupt OCCRA for TIMER0 with a modulo of triggerInterruptInXTicks
void enableTimerA(uint8_t triggerInterruptInXTicks);

// Enable interrupt OCCRB for TIMER0B with a modulo of triggerInterruptInXTicks
void enableTimerB(uint8_t triggerInterruptInXTicks);
void disableTimerB();

// Enable interrupt OCCRA for TIMER1 with a modulo of triggerInterruptInXTicks
void enableFastTimerA(uint8_t triggerInterruptInXTicks);
void disableFastTimerA();

// Return TCNT1
uint8_t getTimestampFromFastTimer();

// Return the time since a timestamp returned by getTimestampFromFastTimer
// Accounts for overflow.
uint8_t getTimeSince(uint8_t timestamp);

// Send a single byte on the built-in SPI interface
// The transfer is done in a serial manner to achieve
// greater throughput.
void sendByteOnSPI(uint8_t byte);

// Set the value of an output pin
void setOutputPin(uint8_t id, bool value);

#endif
