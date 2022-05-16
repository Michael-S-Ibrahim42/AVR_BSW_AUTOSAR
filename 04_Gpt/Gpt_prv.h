/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 15, 2022
**       Version     :	V01
**       SWC         :	Gpt
**       Description :	Gpt module files
** **************************************************************************************/
#ifndef _GPT_PRV_H
#define _GPT_PRV_H
  /* ///////////////////////////////////// MACROS /////////////////////////////////////////////////////////// */
  /* Mode Mask */
  #define GPT_u8MODE_MASK                                              0x48
  #define GPT_u8TIMERS_NUM                                             3
  /* Disable Mask */
  #define GPT_u8DISABLE                                                0x07
  /* Interrupt Masks */
  #define GPT_u8COMPARE_MATCH_INT                                      0x02
  #define GPT_u8OVERFLOW_INT                                           0x01
  /* Reset Values */
  #define GPT_u8ZERO_RESET                                             0x00
  /* //////////////////////////////////////////////////////////////////////////////////////////////////////// */

#endif 