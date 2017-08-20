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
#include "stdio.h"
uint16 count = 0;
int distance_measured;
char countString[16];
char distString[16];
CY_ISR(Timer_ISR_Handler)
{
    UART_1_PutString("TRIGGERED\n");
    Timer_1_ReadStatusRegister();   // Clear interrupts
    count = Timer_1_ReadCounter();  // Give me current value of count
    sprintf(countString, "Count: %d\n" , count);
    UART_1_PutString(countString);
    distance_measured = (65535 - count) / 58;    // Distance measured in cm
    sprintf(distString, "Distance: %d\n\n" ,distance_measured);
    UART_1_PutString(distString);
    
    if (distance_measured < 5)
    {
        LED_Write(1);
    }
    else if (distance_measured >= 5)
    {
        LED_Write(0);
    }
}

int main(void)
{
    UART_1_Start();
    Timer_1_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(Timer_ISR_Handler);    // Give interrupt a handler
    for(;;)
    {
        while(Echo_Read() == 0)
        {
          
            Trigger_Write(1);
            CyDelayUs(10);        // Need to keep trigger pin on for 10ms
            Trigger_Write(0);
        }
        CyDelay(100);
    }
}

/* [] END OF FILE */
