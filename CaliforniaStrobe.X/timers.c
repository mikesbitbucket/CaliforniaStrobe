/*
 * File:   timers.c
 * Author: Mike
 *
 * Created on September 18, 2019, 10:00 PM
 */


#include <stdint.h>
#include "timers.h"
#include "mcc_generated_files/mcc.h"


// Variables
static uint8_t Heartbeat_tmr;

void Inc_Heartbeat_tmr(void)  // Heartbeat timer increment
{
    Heartbeat_tmr++;
}

uint8_t Read_Heartbeat_tmr(void)
{
    uint8_t temp;
    INTERRUPT_GlobalInterruptDisable();
    temp = Heartbeat_tmr;
    INTERRUPT_GlobalInterruptEnable();
    return temp;
}


void Clear_Heartbeat_tmr(void)
{
    INTERRUPT_GlobalInterruptDisable();
    Heartbeat_tmr = 0;
    INTERRUPT_GlobalInterruptEnable();
}

