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
 * 
 * SG-90 Servo
 * Orange = PWM
 * Red = Vcc
 * Brown = GND
 * 
*/
#include "project.h"
#include "stdio.h"
int compare_value;

CY_ISR(SW1_Handler)
{
    LED1_Write(~LED1_Read());
    UART_1_PutString("INTERRUPT!");
    char outputString[4];
    if (compare_value == 1500)
    {
        compare_value = 4500;
        sprintf(outputString, "4500");
        UART_1_PutString(outputString);
    }
    else if (compare_value == 4500)
    {
        compare_value = 1500;
        sprintf(outputString, "1500");
        UART_1_PutString(outputString);
    }
    CyDelay(500);
    PWM_1_WriteCompare(compare_value);
    SW1_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    isr_1_StartEx(SW1_Handler);
    UART_1_Start();
    PWM_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    compare_value = 1500;
    for(;;)
    {


        CyDelay(500);
    }
}

/* [] END OF FILE */
