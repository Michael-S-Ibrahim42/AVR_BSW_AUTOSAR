/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Port
**       Description :	Port module of the MCU "ATMEGA32A"
** **************************************************************************************/
#include "Std_types.h"
#include "Port_prv.h"
void PORT_vidReportError(void)
{
  PORT_u8DET();
}/* PORT_vidReportError */