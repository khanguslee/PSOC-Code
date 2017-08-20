/*******************************************************************************
* File Name: LED_WHT.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED_WHT_ALIASES_H) /* Pins LED_WHT_ALIASES_H */
#define CY_PINS_LED_WHT_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define LED_WHT_0			(LED_WHT__0__PC)
#define LED_WHT_0_INTR	((uint16)((uint16)0x0001u << LED_WHT__0__SHIFT))

#define LED_WHT_INTR_ALL	 ((uint16)(LED_WHT_0_INTR))

#endif /* End Pins LED_WHT_ALIASES_H */


/* [] END OF FILE */
