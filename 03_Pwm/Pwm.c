/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	May 04, 2022
**       Version     :	V01
**       SWC         :	Pwm
**       Description :	Pwm driver files
** **************************************************************************************/
/* ////////////////////////////// Headers inclusion ///////////////////////////////////////////// */
/* LIB Headers */
#include "ATMEGA32A.h"
#include "Std_types.h"
/* Owm headers */
#include "Pwm.h"
#include "Pwm_cfg.h"
#include "Pwm_prv.h"
#include "Pwm_Lcfg.h"
/* ////////////////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////////// Global Section ////////////////////////////////////////////// */
static Pwm_ConfigType* Pwm_pstrConfig = NULL;

/* ////////////////////////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////////// Fns implementation //////////////////////////////////////////// */
/* 
  Description       :         Init the PWM module
  Parameter1        :         The PWM module configurations
  Return            :         void
  **************************** Synchronous *************************************
*/ 
void Pwm_Init(const Pwm_ConfigType* ConfigPtr)
{
  u8 Loc_u8Counter = ZERO_INIT;
  if(ConfigPtr != NULL)
  { 
    Pwm_pstrConfig = (Pwm_ConfigType*)ConfigPtr;
    for(;Loc_u8Counter < PWM_u8CONN_CHANN; Loc_u8Counter++)
    {
      switch(ConfigPtr[Loc_u8Counter].u8ChannelID)
      {
      case(PWM_u8CHANNEL1A):
        TCCR1A = (1<<1) | (1<<7) | ((ConfigPtr[Loc_u8Counter].u8Idle) << 6);
        TCCR1B &= ~(0x7);
        TCCR1B |= (3<<3);
        TCCR1B |= (ConfigPtr[Loc_u8Counter].u32Prescalar & 0x7);
        break;
      case(PWM_u8CHANNEL1B):
        TCCR1A  = (1<<1) | (1<<5) | ((ConfigPtr[Loc_u8Counter].u8Idle) << 4);
        TCCR1B &= ~(0x7);
        TCCR1B |= (3<<3);
        TCCR1B |= (ConfigPtr[Loc_u8Counter].u32Prescalar & 0x7);
        break;
      default:
        /* MISRA */
        break;
      }/* switch */
    }/* for */
  }/* if */
}/* Pwm_Init */
/* 
  Description       :         Set Duty and Frequency of the PWM signal and start timer
  Parameter1        :         The PWM Channel Number
  Parameter2        :         The Duty cycle, options are from 0 to 100
  Parameter3        :         The period, the period is given in milliseconds
  Return            :         void
  ***************** Synchronous ******************
*/
void Pwm_SetPeriodAndDuty(u8 Copy_u8ChannelId,  f32 Copy_f32Duty, u8 Copy_u8Period)
{ 
  u8 Loc_u8Counter = ZERO_INIT;
  u16 Loc_u16Prescalar;
  u8 Loc_u8Idle;
  for(;Loc_u8Counter < PWM_u8CONN_CHANN; Loc_u8Counter++)
  {
    if(Pwm_pstrConfig[Loc_u8Counter].u8ChannelID == Copy_u8ChannelId)
    {
      Loc_u16Prescalar = (Pwm_pstrConfig[Loc_u8Counter].u32Prescalar >> 8);
      Loc_u8Idle = Pwm_pstrConfig[Loc_u8Counter].u8Idle;
    }/* if */
  }/* for */
  u16 Loc_u16Top = (u16)(((f32)PWM_u8FREQ*PWM_u16FREQ_MULT)/((f32)Loc_u16Prescalar/Copy_u8Period)) - 1; 
  switch(Copy_u8ChannelId) 
  {
  case(PWM_u8CHANNEL1A):
      TCCR1A = (1<<1) | (1<<7) | (Loc_u8Idle << 6);
      OCR1A   = (u16)((((u32)Loc_u16Top+1) * Copy_f32Duty) / 100);
      ICR1    = Loc_u16Top;
    break;
  case(PWM_u8CHANNEL1B):
      TCCR1A  = (1<<1) | (1<<5) | (Loc_u8Idle << 4);
      OCR1B   = (u16)((((u32)Loc_u16Top+1) * Copy_f32Duty) / 100);
      ICR1   = Loc_u16Top;
    break;
  default:
    /* MISRA */
    break;
  }/* switch */
}/* Pwm_SetPeriodAndDuty */
/* 
  Description       :         Set the output to the idle value
  Parameter1        :         The PWM Channel Number
  Return            :         void
  ***************** Synchronous ******************
*/
void Pwm_SetOutputToIdle(u8 Copy_u8ChannelId)
{
  u8 Loc_u8Counter = ZERO_INIT;
  u8 Loc_u8Idle;
  for(;Loc_u8Counter < PWM_u8CONN_CHANN; Loc_u8Counter++)
  {
    if(Pwm_pstrConfig[Loc_u8Counter].u8ChannelID == Copy_u8ChannelId)
    {
      Loc_u8Idle = (Pwm_pstrConfig[Loc_u8Counter].u8Idle);
    }/* if */
  }/* for */
  switch(Copy_u8ChannelId) 
  {
  case(PWM_u8CHANNEL1A):
    TCCR1A &= ~(0b11<<6);
    if(Loc_u8Idle == 1)
    {
      PORTD  |= (1<<5);
    }/* if */
    else
    {
      PORTD  &= ~(1<<5);
    }/* else */
    break;
  case(PWM_u8CHANNEL1B):
    TCCR1A &= ~(0b11<<4);
    if(Loc_u8Idle == 1)
    {
      PORTD  |= (1<<4);
    }/* if */
    else
    {
      PORTD  &= ~(1<<4);
    }/* else */
    break;
  default:
    /* MISRA */
    break;
  }/* switch */
}/* Pwm_SetOutputToIdle */
/* ////////////////////////////////////////////////////////////////////////////////////////////// */
