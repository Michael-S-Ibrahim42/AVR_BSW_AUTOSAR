/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 15, 2022
**       Version     :	V01
**       SWC         :	Gpt
**       Description :	Gpt module files
** **************************************************************************************/
#ifndef _GPT_H
#define _GPT_H
  /* ///////////////////////////////////// Defined Types //////////////////////////////////////////////////// */
  typedef struct
  {
    u8 u8Mode;             /* Available options are in "Gpt.h" under "Modes" */
    u8 u8CompareOutput;    /* Available options are in "Gpt.h" under "CompareOutput Modes" */
    u8 u8Prescalar;        /* Available options are in "Gpt.h" under "Prescalar values" */
  }Gpt_ConfigType;
  typedef u16 Gpt_ValueType; /* Gpt value */
  typedef u8  Gpt_ChannelType; /* Channels, options are in "Gpt.h" under "Channel Values" */
  /* //////////////////////////////////////////////////////////////////////////////////////////////////////// */

  /* ///////////////////////////////////// MACROS /////////////////////////////////////////////////////////// */
  /* Modes */
  #define GPT_u8MODE_NORMAL                                              0x00
  #define GPT_u8MODE_CTC                                                 0x08
  /* CompareOutput Modes */
  #define GPT_u8OC0_NORMAL                                               0x00 /* OC0 is disconnected */
  #define GPT_u8OC0_TOGGLE                                               0x10 /* OC0 is toggled on compare match */
  #define GPT_u8OC0_CLEAR                                                0x20 /* OC0 is cleared on compare match */
  #define GPT_u8OC0_SET                                                  0x30 /* OC0 is set on compare match */
  /* Prescalar values */
  #define GPT_u8PRES_1                                                   0x01
  #define GPT_u8PRES_8                                                   0x02
  #define GPT_u8PRES_64                                                  0x03
  #define GPT_u8PRES_256                                                 0x04
  #define GPT_u8PRES_1024                                                0x05
  #define GPT_u8PRES_EXT_CLK_FALLING                                     0x06
  #define GPT_u8PRES_EXT_CLK_RISING                                      0x07
  /* Channels Values */ 
  #define GPT_u8CH0                                                      0
  #define GPT_u8CH1                                                      1
  #define GPT_u8CH2                                                      2
  /* //////////////////////////////////////////////////////////////////////////////////////////////////////// */

  /* ///////////////////////////////////// Interface Fns //////////////////////////////////////////////////// */
  /* 
    Description       :           Initializes the GPT driver. 
    Parameter1        :           Pointer to a selected configuration structure 
    Return            :           void
  */
  void Gpt_Init(const Gpt_ConfigType* ConfigPtr);
  /* 
    Description       :           Deinitializes the GPT driver.  
    Parameter1        :           void
    Return            :           void
  */
  void Gpt_DeInit(void);
  /* 
    Description       :           Returns the time already elapsed.  
    Parameter1        :           Numeric identifier of the GPT channel. 
    Return            :           Returns the time already elapsed
  */
  Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
  /* 
    Description       :           Returns the time remaining until the target time is reached. 
    Parameter1        :           Numeric identifier of the GPT channel. 
    Return            :           Remaining timer value (in number of ticks) 
  */
  Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
  /* 
    Description       :           Starts a timer channel
    Parameter1        :           Numeric identifier of the GPT channel. 
    Parameter2        :           Target time in number of ticks. 
    Return            :           void
  */
  void Gpt_StartTimer (Gpt_ChannelType Channel, Gpt_ValueType Value);
  /* 
    Description       :           Stops a timer channel. 
    Parameter1        :           Numeric identifier of the GPT channel. 
    Return            :           void
  */
  void Gpt_StopTimer(Gpt_ChannelType Channel);
  /* 
    Description       :           Enables the interrupt notification for a channel
    Parameter1        :           Numeric identifier of the GPT channel. 
    Return            :           void
  */
  void Gpt_EnableNotification(Gpt_ChannelType Channel);
  /* 
    Description       :           Disables the interrupt notification for a channel  
    Parameter1        :           Numeric identifier of the GPT channel. 
    Return            :           void
  */
  void Gpt_DisableNotification(Gpt_ChannelType Channel);
  /* 
    Description       :           The overflow interrupt service routine  
    Parameter(s)      :           void 
    Return            :           void
  */
  void __vector_11(void) __attribute__((signal,used));
  /* 
    Description       :           The compare match interrupt service routine  
    Parameter(s)      :           void 
    Return            :           void
  */
  void __vector_10(void) __attribute__((signal,used));
  /* 
    Description       :           Fn to register the callback Fn 
    Parameter1        :           Pointer to the fn 
    Return            :           void
  */
  void Gpt_Notification_CH0(tpfCallbackFn Copy_pfCallback);
  /* //////////////////////////////////////////////////////////////////////////////////////////////////////// */
#endif