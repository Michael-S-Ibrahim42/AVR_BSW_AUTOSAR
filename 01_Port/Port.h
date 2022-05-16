/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Port
**       Description :	Port module of the MCU "ATMEGA32A"
** **************************************************************************************/
#ifndef _PORT_H
#define _PORT_H

  /* ************************* Return Types ************************* */
  typedef enum{
    Port_Ok,
    Port_PinNoError,
    Port_DirError,
    Port_ModeError
  }Port_tenuStatus;
  /* ************************* Directions ************************* */
  #define PORT_u8DIR_IN         0
  #define PORT_u8DIR_OUT        1
    /* *********************** Pin Numbers ************************* */
  #define PORT_u8PIN0           0
  #define PORT_u8PIN1           1
  #define PORT_u8PIN2           2
  #define PORT_u8PIN3           3
  #define PORT_u8PIN4           4
  #define PORT_u8PIN5           5
  #define PORT_u8PIN6           6
  #define PORT_u8PIN7           7
  #define PORT_u8PIN8           8
  #define PORT_u8PIN9           9
  #define PORT_u8PIN10          10  
  #define PORT_u8PIN11          11
  #define PORT_u8PIN12          12    
  #define PORT_u8PIN13          13
  #define PORT_u8PIN14          14
  #define PORT_u8PIN15          15
  #define PORT_u8PIN16          16
  #define PORT_u8PIN17          17  
  #define PORT_u8PIN18          18
  #define PORT_u8PIN19          19
  #define PORT_u8PIN20          20
  #define PORT_u8PIN21          21
  #define PORT_u8PIN22          22
  #define PORT_u8PIN23          23
  #define PORT_u8PIN24          24
  #define PORT_u8PIN25          25
  #define PORT_u8PIN26          26
  #define PORT_u8PIN27          27
  #define PORT_u8PIN28          28
  #define PORT_u8PIN29          29
  #define PORT_u8PIN30          30
  #define PORT_u8PIN31          31
  /* ************************* Pin Modes ************************* */
  #define PORT_u8INPUT_HIGH_IMP   0
  #define PORT_u8INPUT_PULL_UP    1  
  #define PORT_u8OUTPUT           2
    /* ************************* Fns Prototypes ************************* */
  Port_tenuStatus Port_enuSetPinDirection(u8 Copy_u8PinNumber, u8 Copy_u8PinDirection);
  Port_tenuStatus Port_enuSetPinMode(u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
  void Port_vidInit(void);


#endif
