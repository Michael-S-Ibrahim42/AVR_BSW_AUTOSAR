/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Dio
**       Description :	Dio module of the MCU "ATMEGA32A"
** **************************************************************************************/
#ifndef _DIO_H
#define _DIO_H

  /* ************************* Arguments ************************* */
  /* Port numbers */
  #define DIO_u8PORT0          0
  #define DIO_u8PORT1          1
  #define DIO_u8PORT2          2
  #define DIO_u8PORT3          3
  /* Pins numbers */    
  #define DIO_u8PIN0           0
  #define DIO_u8PIN1           1
  #define DIO_u8PIN2           2
  #define DIO_u8PIN3           3
  #define DIO_u8PIN4           4
  #define DIO_u8PIN5           5
  #define DIO_u8PIN6           6
  #define DIO_u8PIN7           7
  #define DIO_u8PIN8           8
  #define DIO_u8PIN9           9
  #define DIO_u8PIN10          10  
  #define DIO_u8PIN11          11
  #define DIO_u8PIN12          12    
  #define DIO_u8PIN13          13
  #define DIO_u8PIN14          14
  #define DIO_u8PIN15          15
  #define DIO_u8PIN16          16
  #define DIO_u8PIN17          17  
  #define DIO_u8PIN18          18
  #define DIO_u8PIN19          19
  #define DIO_u8PIN20          20
  #define DIO_u8PIN21          21
  #define DIO_u8PIN22          22
  #define DIO_u8PIN23          23
  #define DIO_u8PIN24          24
  #define DIO_u8PIN25          25
  #define DIO_u8PIN26          26
  #define DIO_u8PIN27          27
  #define DIO_u8PIN28          28
  #define DIO_u8PIN29          29
  #define DIO_u8PIN30          30
  #define DIO_u8PIN31          31
  /* Channel levels */ 
  #define DIO_u8PIN_LOW        0
  #define DIO_u8PIN_HIGH       1
  /* ************************* Return Types ************************* */
  typedef enum{   
    Dio_Ok                  ,
    Dio_ChannelIdError      ,
    Dio_PortIdError         ,
    Dio_LvlError            
  }Dio_tenuStatus;
  /* ************************* Fns Prototypes ************************* */
  Dio_tenuStatus Dio_enuWriteChannel  (u8 Copy_u8ChannelId  , u8  Copy_u8ChannelLevel   );
  Dio_tenuStatus Dio_enuReadChannel   (u8 Copy_u8ChannelId  , pu8 Add_pu8ChannelLevel   );
  Dio_tenuStatus Dio_enuWritePort     (u8 Copy_u8PortId     , u8  Copy_u8Value          );
  Dio_tenuStatus Dio_enuReadPort      (u8 Copy_u8PortId     , pu8 Add_pu8PortValue      );
  Dio_tenuStatus Dio_enuFlipChannel   (u8 Copy_u8ChannelId                              );

#endif
