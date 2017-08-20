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
#include <stdio.h>

CY_ISR(SW1_Handler)
{
    int light_result;
    char display_result[10];
    
    // Turn on LED
    LED_RED_Write(1);
    
    // Read & print the photodiode result
    light_result = ADC_DelSig_1_Read32();
    sprintf(display_result, "%d\n", light_result);
    UART_1_PutString(display_result);
    
    // Turn off LED
    LED_RED_Write(0);
    
    SW1_ClearInterrupt();
    CyDelay(200);   // A very crude debouncer
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_DelSig_1_Start();
    TIA_1_Start();
    UART_1_Start();
    isr_1_StartEx(SW1_Handler);
    
    for(;;)
    {
      
    }
}

/* [] END OF FILE */
