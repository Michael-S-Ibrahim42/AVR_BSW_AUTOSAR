/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Dio
**       Description :	Dio module of the MCU "ATMEGA32A"
** **************************************************************************************/
#include "Std_types.h"
#include "Dio_prv.h"

/* Fns Implementation */
void Dio_vidReportError(void)
{
  Dio_u8DET();
}/* Port_vidReportError */
