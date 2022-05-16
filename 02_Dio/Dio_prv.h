/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Dio
**       Description :	Dio module of the MCU "ATMEGA32A"
** **************************************************************************************/
#ifndef _DIO_PRV_H
#define _DIO_PRV_H
  
  /* **************************** Ports and Channels_Max **************************** */
  #define DIO_u8MAX_CHANNEL_ID              31
  #define DIO_u8A                           0
  #define DIO_u8B                           1
  #define DIO_u8C                           2
  #define DIO_u8D                           3
  #define DIO_u8PORT_SIZE                   8
  /* Fn Return Values */
  #define DIO_u8NORMAL_RET                  0
  /* **************************** Ports High&Low levels **************************** */
  #define DIO_u8PORT_LOW                    0x00
  #define DIO_u8PORT_HIGH                   0xFF
  /* **************************** Bit Utils MACROS **************************** */
  #define DIO_SET_BIT(REG, BIT)             (REG |=  (1<<BIT))
  #define DIO_CLR_BIT(REG, BIT)             (REG &= ~(1<<BIT))
  #define DIO_GET_BIT(REG, BIT)             ((REG>>BIT) & 0x01)
  #define DIO_TOG_BIT(REG, BIT)             (REG ^= (1<<BIT))
  
  /* ************************* Fns Prototypes ************************* */
  u8 Dio_u8DET(void);/* Development Error Tracer */
  void Dio_vidReportError  (void);

#endif
