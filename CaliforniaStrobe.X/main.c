/**
 California strobe project
 
 rev 1.0
  
 Rev 1.1 - added weak pull up to STOBE_SENSE input. When we lost the old driver with
            Error output, we no longer can sense an open bulb, so pull up to high is
            is the same as no error
            DFP 1.5.133 + Compiler 2.32 - later versions of the DFP generate the unknown 
            attribute warning..
 
*/

/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18345
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "timers.h"
#include <stdio.h>

#define SYSTIC  ((float)(0.01))  // If the system timer changes, change this 'tic' time
#define HEARTBEAT_RATE  ((float)(0.5))  // 1/2 second update
#define HEARTBEAT_CNT   ((uint8_t)(HEARTBEAT_RATE/SYSTIC))

#define Delay_Sw_0      ((uint8_t)(0))   // These are in minutes of Delay for each switch position, seconds if config2 switch = OFF   
#define Delay_Sw_1      ((uint8_t)(5))
#define Delay_Sw_2      ((uint8_t)(7))
#define Delay_Sw_3      ((uint8_t)(9))
#define Delay_Sw_4      ((uint8_t)(11))
#define Delay_Sw_5      ((uint8_t)(13))
#define Delay_Sw_6      ((uint8_t)(15))
#define Delay_Sw_7      ((uint8_t)(20))

#define Delay_Count_0   ((uint16_t)((Delay_Sw_0*60)/HEARTBEAT_RATE))  // counts to compare to
#define Delay_Count_1   ((uint16_t)((Delay_Sw_1*60)/HEARTBEAT_RATE))
#define Delay_Count_2   ((uint16_t)((Delay_Sw_2*60)/HEARTBEAT_RATE))
#define Delay_Count_3   ((uint16_t)((Delay_Sw_3*60)/HEARTBEAT_RATE))
#define Delay_Count_4   ((uint16_t)((Delay_Sw_4*60)/HEARTBEAT_RATE))
#define Delay_Count_5   ((uint16_t)((Delay_Sw_5*60)/HEARTBEAT_RATE))
#define Delay_Count_6   ((uint16_t)((Delay_Sw_6*60)/HEARTBEAT_RATE))
#define Delay_Count_7   ((uint16_t)((Delay_Sw_7*60)/HEARTBEAT_RATE))

#define Delay_Count_Short_0     ((uint16_t)(Delay_Sw_0/HEARTBEAT_RATE))  // the 'Short delay times - seconds
#define Delay_Count_Short_1     ((uint16_t)(Delay_Sw_1/HEARTBEAT_RATE))
#define Delay_Count_Short_2     ((uint16_t)(Delay_Sw_2/HEARTBEAT_RATE))
#define Delay_Count_Short_3     ((uint16_t)(Delay_Sw_3/HEARTBEAT_RATE))
#define Delay_Count_Short_4     ((uint16_t)(Delay_Sw_4/HEARTBEAT_RATE))
#define Delay_Count_Short_5     ((uint16_t)(Delay_Sw_5/HEARTBEAT_RATE))
#define Delay_Count_Short_6     ((uint16_t)(Delay_Sw_6/HEARTBEAT_RATE))
#define Delay_Count_Short_7     ((uint16_t)(Delay_Sw_7/HEARTBEAT_RATE))

// Variables
uint8_t i,j;
uint16_t int_i, int_j;
uint8_t counter, State_B4_Error;
uint8_t Rotary_SW, ConfigBits;
uint8_t st_Main;
uint16_t ShutDown_tmr;
uint8_t Error_Cause;  // hold the error number


const uint16_t Shutdown_Delay[] = 
{
    Delay_Count_0,
    Delay_Count_1,
    Delay_Count_2,
    Delay_Count_3,
    Delay_Count_4,
    Delay_Count_5,
    Delay_Count_6,
    Delay_Count_7,
    Delay_Count_Short_0,
    Delay_Count_Short_1,
    Delay_Count_Short_2,
    Delay_Count_Short_3,
    Delay_Count_Short_4,
    Delay_Count_Short_5,
    Delay_Count_Short_6,
    Delay_Count_Short_7
};



// Enums - this is not used
enum Delays{
    Delay_0 = 0,
    Delay_1 = 5,
    Delay_2 = 7,
    Delay_3 = 9,
    Delay_4 = 11,
    Delay_5 = 13,
    Delay_6 = 15,
    Delay_7 = 20    
};   // these are the delay times of the 'OFF' timer

enum Error_Numbers{
    Error_Driver,
    Error_Timing
};


// State enums for main operation loop
enum Op_State{
    sInit,
    sWait_For_Stop,
    sWait_For_PowerOff,
    sWait_Delay,
    sError
};


/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    st_Main = sInit; 
    
    __delay_ms(100); // Wait to make sure power still here
    if(SW12_DETECT_GetValue() == 1) //Yep power is here
    {
        PWR_HOLD_SetHigh(); // Keep the power on
    }
    else
    {
        // No power - must have been a false start
    }
    
    // Initialize - Flash the LEDs
    for(i=0; i<10; i++)
    {
         LED_GRN_Toggle();
        __delay_ms(50);
        LED_RED_Toggle();
        __delay_ms(50);
    }
    LED_GRN_SetLow();
    LED_RED_SetLow();  // Set them back to off
    
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    // Check if Power is in fact still here - don't want to have power go away then start up becuase power wase
    // going away and Brown out or other thing cause this
    
    
    TMR0_StartTimer(); // Start the heartbeat timer
    
//Initialize Stuff
    
    
    while (1)
    {
      
        // Heartbeat stuff
        // NOTE: If the rate changes here, need to adjust the times of the delays...
        if(Read_Heartbeat_tmr() > HEARTBEAT_CNT) // 500ms
        {
            LED_GRN_Toggle();
            Clear_Heartbeat_tmr();  // Clear the timer
            ShutDown_tmr++;  // Inc the Shutdown timer - 500 minute max
            
            // Check the Config and Rotary switch bits
            Rotary_SW =(~PORTC & 0x07);  // Mask upper - only need the lower 3 bits and invert - '0' reads as all ones
            ConfigBits = (~PORTB & 0x60)>>5;  // Default is both 'ON' so this will be 3
        }
        
        // Main state machine
        //
        // This loop does all the heavy lifting.... not that much to do!
        switch(st_Main)
        {
            case sInit:
            {
                // Not doing anything now, just put this in for possible future stuff to init
                st_Main = sWait_For_Stop;
                // Turn on the Stobe
                STROBE_CNTL_SetHigh();
                break;
            }
            case sWait_For_Stop:
            {
                // We will just sit here with the strobe on until the sign goes to stop or error occurs
                i=STOP_DETECT_GetValue();
                if(STOP_DETECT_GetValue() == 1)
                {
                    // We are at stop - move on
                    st_Main = sWait_For_PowerOff;
                    STROBE_CNTL_SetLow(); // Turn off strobe
                }
                if(STROBE_SENSE_GetValue() == 0)
                {
                    // oh oh - error!
                    if(0 == CONFIG1_GetValue())  // 1 = OFF position - default is ON=0. If OFF - Ignore Error
                    {
                        State_B4_Error = st_Main; // so we know where to come back to...
                        st_Main = sError;
                        Error_Cause = Error_Driver;
                    }
                }
                if(SW12_DETECT_GetValue() == 0)
                {
                    // someone turned off power - we need to shut down....
                    ShutDown_tmr = 0;
                    st_Main = sWait_Delay;
                    STROBE_CNTL_SetHigh();  // Turn on the strobe
                    //PWR_HOLD_SetLow(); // night night
                    //while(1) continue; // stay here until you die...
                }
                break;
            }
            case sWait_For_PowerOff:
            {
                // now we just sit here waiting for the power to go off
                // don't need to check for errors or anything - strobe should be off
                if(SW12_DETECT_GetValue() == 0)
                {
                    // we need to shut down....
                    // turn on strobe and go to shutdown timer case
                    st_Main = sWait_Delay;
                    ShutDown_tmr = 0;
                    STROBE_CNTL_SetHigh();  // Turn on the strobe
                }
                break;
            }
            case sWait_Delay:
            {
                // wait here for delay or another power on - strobe should be ON coming in here
                i = (uint8_t)(CONFIG2_GetValue() << 3);  // This will be zero for default config2 position (minutes) and 8 if set to OFF (Seconds)
                if(ShutDown_tmr > Shutdown_Delay[Rotary_SW + i])
                {
                    // We are done - shut it down
                    PWR_HOLD_SetLow(); // night night
                    while(1) continue; // stay here until you die...
//                    while(1)
//                    {
//                        LED_RED_Toggle();
//                        __delay_ms(500);
//                    }
                }
                // check for power on condition in case they turned it back on
                // Leave strobe on
                if(SW12_DETECT_GetValue() == 1)
                {
                    if(ShutDown_tmr > 2) // wait at lest 1 second to make sure they REALLY applied power and not a glitch
                    {  
                        // They powered it back on - back to init!
                        st_Main = sInit;
                    }
                }
                break;
            }
            case sError:
            {
                // If we got here, an error has occurred - either timing or driver chip fault
                LED_RED_SetHigh();
                // Only error now is the Driver chip pin being low
                // Stay here until it clears
                if(1 == STROBE_SENSE_GetValue()) // Error cleared on Driver
                {
                    // error is clear -
                    LED_RED_SetLow();
                    if(State_B4_Error == sWait_For_Stop)
                    {
                        // Back to this state - Leave strobe on
                        st_Main = sWait_For_Stop;
                    }
                }
                break;
            }
            default:
            {
                st_Main = sInit;
                break;
            }
                    
        } // end switch Main
        
    } // end while(1))
} // End main
/**
 End of File
*/