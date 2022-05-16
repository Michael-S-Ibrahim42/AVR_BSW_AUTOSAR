/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Dio
**       Description :	Dio module of the MCU "ATMEGA32A"
** **************************************************************************************/
/* STD Headers */
#include "Std_types.h"
#include <avr/io.h>
#include "Dio.h"
#include "Dio_prv.h"
#include "Dio_cfg.h"

 Dio_tenuStatus Dio_enuReadChannel   (u8 Copy_u8ChannelId  , pu8 Add_pu8ChannelLevel   );
 Dio_tenuStatus Dio_enuWritePort     (u8 Copy_u8PortId     , u8  Copy_u8Value          );
 Dio_tenuStatus Dio_enuReadPort      (u8 Copy_u8PortId     , pu8 Add_pu8PortValue      );

/* Fns Implementations */
Dio_tenuStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8ChannelLevel)
{
  Dio_tenuStatus Loc_enuRetStat = Dio_Ok;
  u8 Loc_u8Port;
  u8 Loc_u8Pin;
  if(Copy_u8ChannelId > DIO_u8MAX_CHANNEL_ID)
  {
    Loc_enuRetStat = Dio_ChannelIdError;
    Dio_vidReportError();
  }/* if */
  else if(Copy_u8ChannelLevel > DIO_u8PIN_HIGH)
  {
    Loc_enuRetStat = Dio_LvlError;
    Dio_vidReportError();
  }/* else if */
  else
  {
    Loc_u8Port = Copy_u8ChannelId / DIO_u8PORT_SIZE;
    Loc_u8Pin  = Copy_u8ChannelId % DIO_u8PORT_SIZE;
    switch(Loc_u8Port)
    {
      case DIO_u8A:
        if(Copy_u8ChannelLevel == DIO_u8PIN_LOW)
        {
          DIO_CLR_BIT(PORTA, Loc_u8Pin);
        }/* if */
        else
        {
          DIO_SET_BIT(PORTA, Loc_u8Pin);
        }/* else */
        break;
      case DIO_u8B:
        if(Copy_u8ChannelLevel == DIO_u8PIN_LOW)
        {
          DIO_CLR_BIT(PORTB, Loc_u8Pin);
        }/* if */
        else
        {
          DIO_SET_BIT(PORTB, Loc_u8Pin);
        }/* else */
        break;
      case DIO_u8C:
        if(Copy_u8ChannelLevel == DIO_u8PIN_LOW)
        {
          DIO_CLR_BIT(PORTC, Loc_u8Pin);
        }/* if */
        else
        {
          DIO_SET_BIT(PORTC, Loc_u8Pin);
        }/* else */
        break;
      case DIO_u8D:
        if(Copy_u8ChannelLevel == DIO_u8PIN_LOW)
        {
          DIO_CLR_BIT(PORTD, Loc_u8Pin);
        }/* if */
        else
        {
          DIO_SET_BIT(PORTD, Loc_u8Pin);
        }/* else */
        break;
      default:
	    break;
        /* Do Nothing */
    }/* switch */
  }/* else */
  return(Loc_enuRetStat);
}/* Dio_enuWriteChannel */
Dio_tenuStatus Dio_enuReadChannel(u8 Copy_u8ChannelId, pu8 Add_pu8ChannelLevel)
{
  Dio_tenuStatus Loc_enuRetStat = Dio_Ok;
  u8 Loc_u8Port;
  u8 Loc_u8Pin;
  if(Copy_u8ChannelId > DIO_u8MAX_CHANNEL_ID)
  {
    Loc_enuRetStat = Dio_ChannelIdError;
    Dio_vidReportError();
  }/* if */
  else
  {
    Loc_u8Port = Copy_u8ChannelId / DIO_u8PORT_SIZE;
    Loc_u8Pin  = Copy_u8ChannelId % DIO_u8PORT_SIZE;
    switch(Loc_u8Port)
    {
      case DIO_u8A:
        *Add_pu8ChannelLevel = DIO_GET_BIT(PINA, Loc_u8Pin);
        break;
      case DIO_u8B:
        *Add_pu8ChannelLevel = DIO_GET_BIT(PINB, Loc_u8Pin);
        break;
      case DIO_u8C:
        *Add_pu8ChannelLevel = DIO_GET_BIT(PINC, Loc_u8Pin);
        break;
      case DIO_u8D:
        *Add_pu8ChannelLevel = DIO_GET_BIT(PIND, Loc_u8Pin);
        break;
      default:
    	  break;
        /* Do Nothing */
    }/* switch */
  }/* else */    
  return(Loc_enuRetStat);
}/* Dio_enuReadChannel */
Dio_tenuStatus Dio_enuWritePort(u8 Copy_u8PortId, u8 Copy_u8Value)
{
  Dio_tenuStatus Loc_enuRetStat = Dio_Ok;
  if(Copy_u8PortId > DIO_u8PORT3)
  {
    Loc_enuRetStat = Dio_PortIdError;
    Dio_vidReportError();
  }/* if */
  else if(Copy_u8Value > DIO_u8PORT_HIGH)
  {
    Loc_enuRetStat = Dio_LvlError;
    Dio_vidReportError();
  }/* else if */
  else
  {
    switch(Copy_u8PortId)
    {
      case DIO_u8PORT0:
        PORTA = Copy_u8Value;
        break;
      case DIO_u8PORT1:
        PORTB = Copy_u8Value;
        break;
      case DIO_u8PORT2:
        PORTC = Copy_u8Value;
        break;
      case DIO_u8PORT3:
        PORTD = Copy_u8Value;
        break;
      default:
    	  break;
        /* Do Nothing */
    }/* switch */
  }/* else */
  return(Loc_enuRetStat);    
}/* Dio_enuWritePort */
Dio_tenuStatus Dio_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8PortValue)
{
  Dio_tenuStatus Loc_enuRetStat = Dio_Ok;
  if(Copy_u8PortId > DIO_u8PORT3)
  {
    Loc_enuRetStat = Dio_PortIdError;
    Dio_vidReportError();
  }/* if */
  else
  {
    switch(Copy_u8PortId)
    {
      case DIO_u8PORT0:
        *Add_pu8PortValue = PINA;
        break;
      case DIO_u8PORT1:
        *Add_pu8PortValue = PINB;
        break;
      case DIO_u8PORT2:
        *Add_pu8PortValue = PINC;
        break;
      case DIO_u8PORT3:
        *Add_pu8PortValue = PIND;
        break;
      default:
    	break;
        /* Do Nothing */
    }/* switch */
  }/* else */
  return(Loc_enuRetStat);    
}/* Dio_enuReadPort */
Dio_tenuStatus Dio_enuFlipChannel(u8 Copy_u8ChannelId)
{
  Dio_tenuStatus Loc_enuRetStat = Dio_Ok;
  u8 Loc_u8Port;
  u8 Loc_u8Pin;
  if(Copy_u8ChannelId > DIO_u8MAX_CHANNEL_ID)
  {
    Loc_enuRetStat = Dio_ChannelIdError;
    Dio_vidReportError();
  }/* if */
  else
  {
    Loc_u8Port = Copy_u8ChannelId / DIO_u8PORT_SIZE;
    Loc_u8Pin  = Copy_u8ChannelId % DIO_u8PORT_SIZE;
    switch(Loc_u8Port)
    {
      case DIO_u8A:
        DIO_TOG_BIT(PORTA, Loc_u8Pin);
        break;
      case DIO_u8B:
        DIO_TOG_BIT(PORTB, Loc_u8Pin);
        break;
      case DIO_u8C:
        DIO_TOG_BIT(PORTC, Loc_u8Pin);
        break;
      case DIO_u8D:
        DIO_TOG_BIT(PORTD, Loc_u8Pin);
        break;
      default:
    	 break;
        /* Do Nothing */
    }/* switch */
  }/* else */
  return(Loc_enuRetStat);    
}/* Dio_enuFlipChannel */

u8 Dio_u8DET(void)
{
  return(DIO_u8NORMAL_RET);
}/* Dio_u8DET */
