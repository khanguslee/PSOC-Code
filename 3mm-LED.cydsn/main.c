/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

/*

    LED Flasher
    Red LED   - 150 ohm resistor
    Blue LED  - 100 ohm resistor
    Green LED - 100 ohm resistor
    White LED - 100 ohm resistor

*/


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    

    for(;;)
    {
        LED_RED_Write(1);
        CyDelay(500);
        LED_BLU_Write(1);
        CyDelay(500);
        LED_GRN_Write(1);
        CyDelay(500);
        LED_WHT_Write(1);
        CyDelay(500);
        
        LED_RED_Write(0);
        LED_BLU_Write(0);
        LED_GRN_Write(0);
        LED_WHT_Write(0);
        CyDelay(500);
    }
}

/* [] END OF FILE */
