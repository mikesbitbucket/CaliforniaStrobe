/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18345
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set STROBE_CNTL aliases
#define STROBE_CNTL_TRIS                 TRISAbits.TRISA2
#define STROBE_CNTL_LAT                  LATAbits.LATA2
#define STROBE_CNTL_PORT                 PORTAbits.RA2
#define STROBE_CNTL_WPU                  WPUAbits.WPUA2
#define STROBE_CNTL_OD                   ODCONAbits.ODCA2
#define STROBE_CNTL_ANS                  ANSELAbits.ANSA2
#define STROBE_CNTL_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define STROBE_CNTL_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define STROBE_CNTL_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define STROBE_CNTL_GetValue()           PORTAbits.RA2
#define STROBE_CNTL_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define STROBE_CNTL_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define STROBE_CNTL_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define STROBE_CNTL_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define STROBE_CNTL_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define STROBE_CNTL_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define STROBE_CNTL_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define STROBE_CNTL_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set PWR_HOLD aliases
#define PWR_HOLD_TRIS                 TRISAbits.TRISA4
#define PWR_HOLD_LAT                  LATAbits.LATA4
#define PWR_HOLD_PORT                 PORTAbits.RA4
#define PWR_HOLD_WPU                  WPUAbits.WPUA4
#define PWR_HOLD_OD                   ODCONAbits.ODCA4
#define PWR_HOLD_ANS                  ANSELAbits.ANSA4
#define PWR_HOLD_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define PWR_HOLD_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define PWR_HOLD_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define PWR_HOLD_GetValue()           PORTAbits.RA4
#define PWR_HOLD_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define PWR_HOLD_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define PWR_HOLD_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define PWR_HOLD_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define PWR_HOLD_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define PWR_HOLD_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define PWR_HOLD_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define PWR_HOLD_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SW12_DETECT aliases
#define SW12_DETECT_TRIS                 TRISAbits.TRISA5
#define SW12_DETECT_LAT                  LATAbits.LATA5
#define SW12_DETECT_PORT                 PORTAbits.RA5
#define SW12_DETECT_WPU                  WPUAbits.WPUA5
#define SW12_DETECT_OD                   ODCONAbits.ODCA5
#define SW12_DETECT_ANS                  ANSELAbits.ANSA5
#define SW12_DETECT_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW12_DETECT_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW12_DETECT_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW12_DETECT_GetValue()           PORTAbits.RA5
#define SW12_DETECT_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW12_DETECT_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW12_DETECT_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW12_DETECT_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW12_DETECT_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SW12_DETECT_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SW12_DETECT_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SW12_DETECT_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set STROBE_SENSE aliases
#define STROBE_SENSE_TRIS                 TRISBbits.TRISB4
#define STROBE_SENSE_LAT                  LATBbits.LATB4
#define STROBE_SENSE_PORT                 PORTBbits.RB4
#define STROBE_SENSE_WPU                  WPUBbits.WPUB4
#define STROBE_SENSE_OD                   ODCONBbits.ODCB4
#define STROBE_SENSE_ANS                  ANSELBbits.ANSB4
#define STROBE_SENSE_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define STROBE_SENSE_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define STROBE_SENSE_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define STROBE_SENSE_GetValue()           PORTBbits.RB4
#define STROBE_SENSE_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define STROBE_SENSE_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define STROBE_SENSE_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define STROBE_SENSE_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define STROBE_SENSE_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define STROBE_SENSE_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define STROBE_SENSE_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define STROBE_SENSE_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set CONFIG1 aliases
#define CONFIG1_TRIS                 TRISBbits.TRISB5
#define CONFIG1_LAT                  LATBbits.LATB5
#define CONFIG1_PORT                 PORTBbits.RB5
#define CONFIG1_WPU                  WPUBbits.WPUB5
#define CONFIG1_OD                   ODCONBbits.ODCB5
#define CONFIG1_ANS                  ANSELBbits.ANSB5
#define CONFIG1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define CONFIG1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define CONFIG1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define CONFIG1_GetValue()           PORTBbits.RB5
#define CONFIG1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define CONFIG1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define CONFIG1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define CONFIG1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define CONFIG1_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define CONFIG1_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define CONFIG1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define CONFIG1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set CONFIG2 aliases
#define CONFIG2_TRIS                 TRISBbits.TRISB6
#define CONFIG2_LAT                  LATBbits.LATB6
#define CONFIG2_PORT                 PORTBbits.RB6
#define CONFIG2_WPU                  WPUBbits.WPUB6
#define CONFIG2_OD                   ODCONBbits.ODCB6
#define CONFIG2_ANS                  ANSELBbits.ANSB6
#define CONFIG2_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define CONFIG2_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define CONFIG2_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define CONFIG2_GetValue()           PORTBbits.RB6
#define CONFIG2_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define CONFIG2_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define CONFIG2_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define CONFIG2_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define CONFIG2_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define CONFIG2_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define CONFIG2_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define CONFIG2_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set LED_GRN aliases
#define LED_GRN_TRIS                 TRISBbits.TRISB7
#define LED_GRN_LAT                  LATBbits.LATB7
#define LED_GRN_PORT                 PORTBbits.RB7
#define LED_GRN_WPU                  WPUBbits.WPUB7
#define LED_GRN_OD                   ODCONBbits.ODCB7
#define LED_GRN_ANS                  ANSELBbits.ANSB7
#define LED_GRN_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define LED_GRN_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define LED_GRN_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define LED_GRN_GetValue()           PORTBbits.RB7
#define LED_GRN_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define LED_GRN_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define LED_GRN_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define LED_GRN_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define LED_GRN_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define LED_GRN_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define LED_GRN_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define LED_GRN_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISCbits.TRISC0
#define SW1_LAT                  LATCbits.LATC0
#define SW1_PORT                 PORTCbits.RC0
#define SW1_WPU                  WPUCbits.WPUC0
#define SW1_OD                   ODCONCbits.ODCC0
#define SW1_ANS                  ANSELCbits.ANSC0
#define SW1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SW1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SW1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SW1_GetValue()           PORTCbits.RC0
#define SW1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SW1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISCbits.TRISC1
#define SW2_LAT                  LATCbits.LATC1
#define SW2_PORT                 PORTCbits.RC1
#define SW2_WPU                  WPUCbits.WPUC1
#define SW2_OD                   ODCONCbits.ODCC1
#define SW2_ANS                  ANSELCbits.ANSC1
#define SW2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SW2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SW2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SW2_GetValue()           PORTCbits.RC1
#define SW2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SW2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SW4 aliases
#define SW4_TRIS                 TRISCbits.TRISC2
#define SW4_LAT                  LATCbits.LATC2
#define SW4_PORT                 PORTCbits.RC2
#define SW4_WPU                  WPUCbits.WPUC2
#define SW4_OD                   ODCONCbits.ODCC2
#define SW4_ANS                  ANSELCbits.ANSC2
#define SW4_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SW4_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SW4_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SW4_GetValue()           PORTCbits.RC2
#define SW4_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SW4_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SW4_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SW4_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SW4_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SW4_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SW4_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SW4_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SW8 aliases
#define SW8_TRIS                 TRISCbits.TRISC3
#define SW8_LAT                  LATCbits.LATC3
#define SW8_PORT                 PORTCbits.RC3
#define SW8_WPU                  WPUCbits.WPUC3
#define SW8_OD                   ODCONCbits.ODCC3
#define SW8_ANS                  ANSELCbits.ANSC3
#define SW8_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SW8_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SW8_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SW8_GetValue()           PORTCbits.RC3
#define SW8_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SW8_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SW8_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SW8_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SW8_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SW8_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SW8_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SW8_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SLOW_DETECT aliases
#define SLOW_DETECT_TRIS                 TRISCbits.TRISC4
#define SLOW_DETECT_LAT                  LATCbits.LATC4
#define SLOW_DETECT_PORT                 PORTCbits.RC4
#define SLOW_DETECT_WPU                  WPUCbits.WPUC4
#define SLOW_DETECT_OD                   ODCONCbits.ODCC4
#define SLOW_DETECT_ANS                  ANSELCbits.ANSC4
#define SLOW_DETECT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SLOW_DETECT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SLOW_DETECT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SLOW_DETECT_GetValue()           PORTCbits.RC4
#define SLOW_DETECT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SLOW_DETECT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SLOW_DETECT_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SLOW_DETECT_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SLOW_DETECT_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SLOW_DETECT_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SLOW_DETECT_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SLOW_DETECT_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set STOP_DETECT aliases
#define STOP_DETECT_TRIS                 TRISCbits.TRISC5
#define STOP_DETECT_LAT                  LATCbits.LATC5
#define STOP_DETECT_PORT                 PORTCbits.RC5
#define STOP_DETECT_WPU                  WPUCbits.WPUC5
#define STOP_DETECT_OD                   ODCONCbits.ODCC5
#define STOP_DETECT_ANS                  ANSELCbits.ANSC5
#define STOP_DETECT_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define STOP_DETECT_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define STOP_DETECT_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define STOP_DETECT_GetValue()           PORTCbits.RC5
#define STOP_DETECT_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define STOP_DETECT_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define STOP_DETECT_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define STOP_DETECT_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define STOP_DETECT_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define STOP_DETECT_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define STOP_DETECT_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define STOP_DETECT_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set TP1 aliases
#define TP1_TRIS                 TRISCbits.TRISC6
#define TP1_LAT                  LATCbits.LATC6
#define TP1_PORT                 PORTCbits.RC6
#define TP1_WPU                  WPUCbits.WPUC6
#define TP1_OD                   ODCONCbits.ODCC6
#define TP1_ANS                  ANSELCbits.ANSC6
#define TP1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define TP1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define TP1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define TP1_GetValue()           PORTCbits.RC6
#define TP1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define TP1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define TP1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define TP1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define TP1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define TP1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define TP1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define TP1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LED_RED aliases
#define LED_RED_TRIS                 TRISCbits.TRISC7
#define LED_RED_LAT                  LATCbits.LATC7
#define LED_RED_PORT                 PORTCbits.RC7
#define LED_RED_WPU                  WPUCbits.WPUC7
#define LED_RED_OD                   ODCONCbits.ODCC7
#define LED_RED_ANS                  ANSELCbits.ANSC7
#define LED_RED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED_RED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED_RED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED_RED_GetValue()           PORTCbits.RC7
#define LED_RED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED_RED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED_RED_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED_RED_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED_RED_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED_RED_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED_RED_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define LED_RED_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/