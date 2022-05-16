/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Port
**       Description :	Port module of the MCU "ATMEGA32A"
** **************************************************************************************/
#include "Std_types.h"
#include <avr/io.h>
#include "Port.h"
#include "Port_prv.h"
#include "Port_cfg.h"

/* Fns Implementations */
Port_tenuStatus Port_enuSetPinDirection (u8 Copy_u8PinNumber, u8 Copy_u8PinDirection )
{
  Port_tenuStatus Loc_enuReturnStatus = Port_Ok;
  u8 Loc_u8Port;
  u8 Loc_u8Pin;
  if(Copy_u8PinNumber > PORT_u8MAN_PIN_NO)
  {
    Loc_enuReturnStatus = Port_PinNoError;
    PORT_vidReportError();
  }/* if */
  else if(Copy_u8PinDirection > PORT_u8DIR_OUT)
  {
    Loc_enuReturnStatus = Port_DirError;    
    PORT_vidReportError();
  }/* else if */
  else 
  {
    Loc_u8Port = Copy_u8PinNumber / PORT_u8PORT_SIZE;
    Loc_u8Pin  = Copy_u8PinNumber % PORT_u8PORT_SIZE;
    switch(Loc_u8Port)
    {
      case(PORT_u8A):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRA, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRA, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8B):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRB, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRB, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8C):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRC, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRC, Loc_u8Pin);
        }/* else */
        break; 
      case(PORT_u8D):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRD, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRD, Loc_u8Pin);
        }/* else */
        break;
      default:
        break;
    }/* switch */
  }/* else */
  return(Loc_enuReturnStatus);
}/* Port_enuSetPinDirection */
Port_tenuStatus Port_enuSetPinMode(u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
  Port_tenuStatus Loc_enuReturnStatus = Port_Ok;
  u8 Loc_u8Port;
  u8 Loc_u8Pin;
  if(Copy_u8PinNumber > PORT_u8MAN_PIN_NO)
  {
    Loc_enuReturnStatus = Port_PinNoError;
    PORT_vidReportError();
  }/* if */
  else if(Copy_u8PinMode > PORT_u8OUTPUT)
  {
    Loc_enuReturnStatus = Port_ModeError;    
    PORT_vidReportError();
  }/* else if */
  else 
  {
    Loc_u8Port = Copy_u8PinNumber / PORT_u8PORT_SIZE;
    Loc_u8Pin  = Copy_u8PinNumber % PORT_u8PORT_SIZE;
    switch(Loc_u8Port)
    {
      case(PORT_u8A):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRA, Loc_u8Pin);
          PORT_CLR_BIT(PORTA, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRA, Loc_u8Pin);
          PORT_SET_BIT(PORTA, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRA, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8B):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRB, Loc_u8Pin);
          PORT_CLR_BIT(PORTB, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRB, Loc_u8Pin);
          PORT_SET_BIT(PORTB, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRB, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8C):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRC, Loc_u8Pin);
          PORT_CLR_BIT(PORTC, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRC, Loc_u8Pin);
          PORT_SET_BIT(PORTC, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRC, Loc_u8Pin);
        }/* else */
        break; 
      case(PORT_u8D):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRD, Loc_u8Pin);
          PORT_CLR_BIT(PORTD, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRD, Loc_u8Pin);
          PORT_SET_BIT(PORTD, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRD, Loc_u8Pin);
        }/* else */
        break;
      default:
        break;
    }/* switch */
  }/* else */
  return(Loc_enuReturnStatus);  
}/* Port_enuSetPinMode */
void Port_vidInit(void)
{
  #undef PORT_u8INPUT_HI         
  #undef PORT_u8INPUT_PU         
  #undef PORT_u8OUTPUT  
  #define PORT_u8INPUT_HI                    0       
  #define PORT_u8INPUT_PU                    0
  #define PORT_u8OUTPUT                      1
  DDRA = CONC(PORT_u8MODE_PIN7,PORT_u8MODE_PIN6,PORT_u8MODE_PIN5,PORT_u8MODE_PIN4,PORT_u8MODE_PIN3,PORT_u8MODE_PIN2,PORT_u8MODE_PIN1,PORT_u8MODE_PIN0);
  DDRB = CONC(PORT_u8MODE_PIN15,PORT_u8MODE_PIN14,PORT_u8MODE_PIN13,PORT_u8MODE_PIN12,PORT_u8MODE_PIN11,PORT_u8MODE_PIN10,PORT_u8MODE_PIN9,PORT_u8MODE_PIN8);
  DDRC = CONC(PORT_u8MODE_PIN23,PORT_u8MODE_PIN22,PORT_u8MODE_PIN21,PORT_u8MODE_PIN20,PORT_u8MODE_PIN19,PORT_u8MODE_PIN18,PORT_u8MODE_PIN17,PORT_u8MODE_PIN16);
  DDRD = CONC(PORT_u8MODE_PIN31,PORT_u8MODE_PIN30,PORT_u8MODE_PIN29,PORT_u8MODE_PIN28,PORT_u8MODE_PIN27,PORT_u8MODE_PIN26,PORT_u8MODE_PIN25,PORT_u8MODE_PIN24);
  #undef PORT_u8INPUT_HI         
  #undef PORT_u8INPUT_PU         
  #undef PORT_u8OUTPUT  
  #define PORT_u8INPUT_HI                   0       
  #define PORT_u8INPUT_PU                   1
  #define PORT_u8OUTPUT                     0
  PORTA = CONC(PORT_u8MODE_PIN7,PORT_u8MODE_PIN6,PORT_u8MODE_PIN5,PORT_u8MODE_PIN4,PORT_u8MODE_PIN3,PORT_u8MODE_PIN2,PORT_u8MODE_PIN1,PORT_u8MODE_PIN0);
  PORTB = CONC(PORT_u8MODE_PIN15,PORT_u8MODE_PIN14,PORT_u8MODE_PIN13,PORT_u8MODE_PIN12,PORT_u8MODE_PIN11,PORT_u8MODE_PIN10,PORT_u8MODE_PIN9,PORT_u8MODE_PIN8);
  PORTC = CONC(PORT_u8MODE_PIN23,PORT_u8MODE_PIN22,PORT_u8MODE_PIN21,PORT_u8MODE_PIN20,PORT_u8MODE_PIN19,PORT_u8MODE_PIN18,PORT_u8MODE_PIN17,PORT_u8MODE_PIN16);
  PORTD = CONC(PORT_u8MODE_PIN31,PORT_u8MODE_PIN30,PORT_u8MODE_PIN29,PORT_u8MODE_PIN28,PORT_u8MODE_PIN27,PORT_u8MODE_PIN26,PORT_u8MODE_PIN25,PORT_u8MODE_PIN24);
}/* Port_vidInit */

u8 PORT_u8DET(void)
{
  return(PORT_u8NORMAL_RET);
}/* PORT_u8DET */
