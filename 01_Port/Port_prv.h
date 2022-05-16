/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Port
**       Description :	Port module of the MCU "ATMEGA32A"
** **************************************************************************************/
#ifndef _PORT_PRV_H
#define _PORT_PRV_H
  /* **************************** Pins Modes **************************************** */
  #define PORT_u8INPUT_HI                              0
  #define PORT_u8INPUT_PU                              1
  #define PORT_u8OUTPUT                                2
  /* Fn Return values */
  #define PORT_u8NORMAL_RET                            0
  /* ******************************************************************************** */
  /* **************************** Ports and Channels_Max **************************** */
  #define PORT_u8MAN_PIN_NO                           31
  #define PORT_u8A                                    0
  #define PORT_u8B                                    1
  #define PORT_u8C                                    2
  #define PORT_u8D                                    3
  #define PORT_u8PORT_SIZE                            8
  /* **************************** Bit Utils MACROS **************************** */
  #define CONC(B7,B6,B5,B4,B3,B2,B1,B0)               CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
  #define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)          0b##B7##B6##B5##B4##B3##B2##B1##B0
  #define PORT_SET_BIT(REG, BIT)                      (REG |= (1 << BIT))
  #define PORT_CLR_BIT(REG, BIT)                      (REG &= ~(1 << BIT))
  /* ************************* Fns Prototypes ************************* */
  u8 PORT_u8DET(void);
  void PORT_vidReportError(void);

#endif