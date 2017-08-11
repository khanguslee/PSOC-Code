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

CY_ISR(SW1_Handler)
{
    LED1_Write(~LED1_Read());
    UART_1_PutString("INTERRUPT!");
    int compare_value = 3000;
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
    int compare_value = 2000;
    for(;;)
    {
        if (compare_value == 2000)
        {
            compare_value = 4000;
            UART_1_PutString("Up!");
        }
        else if (compare_value == 4000)
        {
            compare_value = 2000;
            UART_1_PutString("Down!");
        }
        else
        {
            compare_value = 2000;
        }
        UART_1_PutString("TURNING");
        PWM_1_WriteCompare(compare_value);

        CyDelay(500);
    }
}

/* [] END OF FILE */
