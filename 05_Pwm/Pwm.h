/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	May 04, 2022
**       Version     :	V01
**       SWC         :	Pwm
**       Description :	Pwm driver files
** **************************************************************************************/
#ifndef _PWM_H
#define _PWM_H
  /* ////////////////////////////////// Defined types ///////////////////////////////////// */
  typedef struct
  {
    u32 u32Prescalar;        /* The prescalar value, options are in "Pwm.h" under "Prescalar Values" */
    u8  u8ChannelID;         /* set the channel ID, Options are in "Pwm.h" under "Available Channels" */
    u8  u8Idle;              /* Set the signal idle state, Options are in "Pwm.h" under "Signal Levels" */
    u8  u8ChannelType;       /* Set the channel type, Options are in "Pwm.h" under "Channel Types" */
  }Pwm_ConfigType;
  /* /////////////////////////////////////////////////////////////////////////////////////// */
  /* /////////////////////////////////// MACROS //////////////////////////////////////////// */
  /* Available Channels */
  #define PWM_u8CHANNEL0                                           ((u8)(0))
  #define PWM_u8CHANNEL1A                                          ((u8)(1))
  #define PWM_u8CHANNEL1B                                          ((u8)(2))
  #define PWM_u8CHANNEL2                                           ((u8)(3))
  /* Signal Levels */
  #define PWM_u8LOW                                                ((u8)(0))
  #define PWM_u8HIGH                                               ((u8)(1))
  /* Channel Types */
  #define PWM_u8FIXED_CHANNEL                                      ((u8)(0))
  #define PWM_u8VARIABLE_CHANNEL                                   ((u8)(1))
  /* Prescalar Values */
  #define PWM_u32PRESCAL_1                                         ((u32)(0x00101))
  #define PWM_u32PRESCAL_8                                         ((u32)(0x00802))
  #define PWM_u32PRESCAL_64                                        ((u32)(0x04003))
  #define PWM_u32PRESCAL_256                                       ((u32)(0x10004))
  #define PWM_u32PRESCAL_1024                                      ((u32)(0x40005))
  /* /////////////////////////////////////////////////////////////////////////////////////// */

  /* /////////////////////////////////// Interface Fns //////////////////////////////////////////// */
  /* 
    Description       :         Init the PWM module
    Parameter1        :         The PWM module configurations
    Return            :         void
    **************************** Synchronous *************************************
  */ 
  void Pwm_Init(const Pwm_ConfigType* ConfigPtr);
  /* 
    Description       :         Set Duty and Frequency of the PWM signal and start timer
    Parameter1        :         The PWM Channel Number
    Parameter2        :         The Duty cycle, options are from 0 to 100
    Parameter3        :         The period, the period is given in milliseconds
    Return            :         void
    ***************** Synchronous ******************
  */
  void Pwm_SetPeriodAndDuty(u8 Copy_u8ChannelId,  f32 Copy_f32Duty, u8 Copy_u8Period);
  /* 
    Description       :         Set the output to the idle value
    Parameter1        :         The PWM Channel Number
    Return            :         void
    ***************** Synchronous ******************
  */
  void Pwm_SetOutputToIdle(u8 Copy_u8ChannelId);
  /* /////////////////////////////////////////////////////////////////////////////////////// */

#endif
