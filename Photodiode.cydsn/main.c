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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_DelSig_1_Start();
    TIA_1_Start();
    UART_1_Start();
    
    int light_result;
    char display_result[10];
    
    for(;;)
    {
        light_result = ADC_DelSig_1_Read32();
        sprintf(display_result, "%d\n", light_result);
        UART_1_PutString(display_result);
        CyDelay(1000);
    }
}

/* [] END OF FILE */
