/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 15, 2022
**       Version     :	V01
**       SWC         :	Gpt
**       Description :	Gpt module files
** **************************************************************************************/
/* ////////////////////////////////////////////// Headers inclusion ////////////////////////////////////////////////// */
/* STD headers */
#include "avr/io.h"
#include "Std_types.h"
/* Own headers */
#include "Gpt.h"
#include "Gpt_cfg.h"
#include "Gpt_prv.h"
/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////////////////////////// Global Variables /////////////////////////////////////////////////// */
u8 Gpt_au8PrescalarValues[GPT_u8TIMERS_NUM];
u8 Gpt_au8TimerInitialValues[GPT_u8TIMERS_NUM];
u8 Gpt_au8TimerTargetValues[GPT_u8TIMERS_NUM];
u8 Gpt_au8TimerMode[GPT_u8TIMERS_NUM];
u8 Gpt_au8Overflow[GPT_u8TIMERS_NUM];
u8 Gpt_au8TCNT0_Start[GPT_u8TIMERS_NUM];
static tpfCallbackFn Gpt_apfCallbackFn[GPT_u8TIMERS_NUM];/* Callback Fns pointers */
/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////////////////////////// Interface Fns ////////////////////////////////////////////////////// */
/* 
  Description       :           Initializes the GPT driver. 
  Parameter1        :           Pointer to a selected configuration structure 
  Return            :           void
*/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
  /*  Select Mode
      Select OC0 output config
      Select clock
      Disable Interrupts */
  u8 Loc_u8Counter = ZERO_INIT;
  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < GPT_u8TIMERS_NUM; Loc_u8Counter++)
  {
    if(Loc_u8Counter == 0)
    {
      TCCR0 = (ConfigPtr->u8Mode) | (ConfigPtr->u8CompareOutput); /* Selecting Mode and OC0 output config */
      Gpt_au8PrescalarValues[Loc_u8Counter] = ConfigPtr->u8Prescalar; /* Saving the prescalar */
      Gpt_au8TimerMode[Loc_u8Counter] = ConfigPtr->u8Mode; /* Saving the Modes */
      TIMSK &= ~(GPT_u8COMPARE_MATCH_INT | GPT_u8OVERFLOW_INT);/* Disable interrupts */
    }/* if */
    else
    {
      /* MISRA */
    }/* else */
  }/* for */
}/* Gpt_Init */
/* 
  Description       :           Deinitializes the GPT driver.  
  Parameter1        :           void
  Return            :           void
*/
void Gpt_DeInit(void)
{
  /* Reset registers */
  u8 Loc_u8Counter = ZERO_INIT;
  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < GPT_u8TIMERS_NUM; Loc_u8Counter++)
  {
    if(Loc_u8Counter == 0)
    {
      TCCR0 = GPT_u8ZERO_RESET;
      Gpt_au8PrescalarValues[Loc_u8Counter] = GPT_u8ZERO_RESET;/* Saving the prescalar */
      TIMSK = GPT_u8ZERO_RESET;
    }/* if */
    else
    {
      /* MISRA */
    }/* else */
  }/* for */
}/* Gpt_DeInit */
/* 
  Description       :           Returns the time already elapsed.  
  Parameter1        :           Numeric identifier of the GPT channel. 
  Return            :           Returns the time already elapsed
*/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel) 
{
  Gpt_ValueType Loc_u8TimeElapsed = ZERO_INIT;
  if(Channel == GPT_u8CH0)
  {
    Loc_u8TimeElapsed = TCNT0 - Gpt_au8TimerInitialValues[Channel];
  }/* if */

  return(Loc_u8TimeElapsed);
}/* Gpt_GetTimeElapsed */
/* 
  Description       :           Returns the time remaining until the target time is reached. 
  Parameter1        :           Numeric identifier of the GPT channel. 
  Return            :           Remaining timer value (in number of ticks) 
*/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel) 
{
  Gpt_ValueType Loc_u8TimeRemaining = ZERO_INIT;
  if(Channel == GPT_u8CH0)
  {
    Loc_u8TimeRemaining = Gpt_au8TimerTargetValues[Channel] - TCNT0;
  }/* if */

  return(Loc_u8TimeRemaining);
}/* Gpt_GetTimeRemaining */
/* 
  Description       :           Starts a timer channel
  Parameter1        :           Numeric identifier of the GPT channel. 
  Parameter2        :           Target time in number of ticks. 
  Return            :           void
*/
void Gpt_StartTimer (Gpt_ChannelType Channel, Gpt_ValueType Value)
{
  if(Channel == GPT_u8CH0)
  {
    if(Gpt_au8TimerMode[Channel] == GPT_u8MODE_NORMAL)
    {
      Gpt_au8Overflow[Channel] = Value / 256;
      Gpt_au8TCNT0_Start[Channel] = (u8)(256 - (Value % 256));
      TCNT0 = (u8)(256 - (Value % 256));
      TCCR0 |= Gpt_au8PrescalarValues[Channel];
      Gpt_au8Overflow[Channel] += 1;
    }/* if */
    else
    {
      OCR0 = Value;
      TCCR0 |= Gpt_au8PrescalarValues[Channel];
    }/* else */
  }/* if */
}/* Gpt_StartTimer */
/* 
  Description       :           Stops a timer channel. 
  Parameter1        :           Numeric identifier of the GPT channel. 
  Return            :           void
*/
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
  if(Channel == GPT_u8CH0)
  {
    TCCR0 &= ~GPT_u8DISABLE;
  }/* if */
}/* Gpt_StopTimer */
/* 
  Description       :           Enables the interrupt notification for a channel
  Parameter1        :           Numeric identifier of the GPT channel. 
  Return            :           void
*/
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
  if(Channel == GPT_u8CH0)
  {
    if(Gpt_au8TimerMode[Channel] == GPT_u8MODE_NORMAL)
    {
      TIMSK |= GPT_u8OVERFLOW_INT;          /* Enable overflow interrupt */
    }/* if */
    else
    {
      TIMSK |= GPT_u8COMPARE_MATCH_INT;     /* Enable compare match interrupt */
    }/* else */
  }/* if */  
}/* Gpt_EnableNotification */
/* 
  Description       :           Disables the interrupt notification for a channel  
  Parameter1        :           Numeric identifier of the GPT channel. 
  Return            :           void
*/
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
  if(Channel == GPT_u8CH0)
  {
    if(Gpt_au8TimerMode[Channel] == GPT_u8MODE_NORMAL)
    {
      TIMSK &= ~GPT_u8OVERFLOW_INT;          /* Disable overflow interrupt */
    }/* if */
    else
    {
      TIMSK &= ~GPT_u8COMPARE_MATCH_INT;     /* Disable compare match interrupt */
    }/* else */
  }/* if */  
}/* Gpt_DisableNotification */
/* 
  Description       :           Fn to register the callback Fn 
  Parameter1        :           Pointer to the fn 
  Return            :           void
*/
void Gpt_Notification_CH0(tpfCallbackFn Copy_pfCallback)
{
  if(Copy_pfCallback != NULL)
  {
    Gpt_apfCallbackFn[GPT_u8CH0] = Copy_pfCallback;
  }/* if */
}

/* 
  Description       :           The overflow interrupt service routine  
  Parameter(s)      :           void 
  Return            :           void
*/
void __vector_11(void)
{
  static u8 Loc_u8Overflow = 0;
  if(Loc_u8Overflow == 0)
  {
	  Loc_u8Overflow = Gpt_au8Overflow[GPT_u8CH0];
  }
  Loc_u8Overflow--;
  if(Loc_u8Overflow == 0)
  {
	TCNT0 = Gpt_au8TCNT0_Start[GPT_u8CH0];
	if(Gpt_apfCallbackFn[GPT_u8CH0] != NULL)
    {
      Gpt_apfCallbackFn[GPT_u8CH0]();
    }/* if */
  }/* if */
}
/* 
  Description       :           The compare match interrupt service routine  
  Parameter(s)      :           void 
  Return            :           void
*/
void __vector_10(void)
{

}
/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
