/***********************************************/
/****By:mohamed salah***************************/
/****DIO_CONFIGURATION.H   ***************************/
/****24/6/2022 9:35pm Portsaid East**************/ 

#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_


//Pin config ( DIO_INPUT  or DIO_OUTPUT)

#define DIO_u8_DIR_PA0  DIO_OUTPUT 	  //lcd
#define DIO_u8_DIR_PA1  DIO_OUTPUT	  //lcd
#define DIO_u8_DIR_PA2  DIO_OUTPUT	  //lcd
#define DIO_u8_DIR_PA3  DIO_OUTPUT	  //lcd
#define DIO_u8_DIR_PA4  DIO_OUTPUT	  //lcd
#define DIO_u8_DIR_PA5  DIO_OUTPUT	  //lcd
#define DIO_u8_DIR_PA6  DIO_OUTPUT	  //lcd
#define DIO_u8_DIR_PA7  DIO_OUTPUT	  //lcd

#define DIO_u8_DIR_PB0  DIO_OUTPUT
#define DIO_u8_DIR_PB1  DIO_OUTPUT    	//lcd
#define DIO_u8_DIR_PB2  DIO_OUTPUT		//lcd
#define DIO_u8_DIR_PB3  DIO_OUTPUT		//lcd
#define DIO_u8_DIR_PB4  DIO_INPUT
#define DIO_u8_DIR_PB5  DIO_INPUT
#define DIO_u8_DIR_PB6  DIO_INPUT
#define DIO_u8_DIR_PB7  DIO_INPUT

#define DIO_u8_DIR_PC0  DIO_OUTPUT
#define DIO_u8_DIR_PC1  DIO_OUTPUT
#define DIO_u8_DIR_PC2  DIO_OUTPUT
#define DIO_u8_DIR_PC3  DIO_OUTPUT  //H-BRIDGE
#define DIO_u8_DIR_PC4  DIO_OUTPUT  //H-BRIDGE
#define DIO_u8_DIR_PC5  DIO_OUTPUT  //H-BRIDGE
#define DIO_u8_DIR_PC6  DIO_OUTPUT  //H-BRIDGE
#define DIO_u8_DIR_PC7  DIO_INPUT

#define DIO_u8_DIR_PD0  DIO_INPUT
#define DIO_u8_DIR_PD1  DIO_INPUT
#define DIO_u8_DIR_PD2  DIO_INPUT
#define DIO_u8_DIR_PD3  DIO_OUTPUT
#define DIO_u8_DIR_PD4  DIO_INPUT
#define DIO_u8_DIR_PD5  DIO_INPUT
#define DIO_u8_DIR_PD6  DIO_INPUT
#define DIO_u8_DIR_PD7  DIO_INPUT

#define DIO_u8_DIR_PORTA  ConcPort(DIO_u8_DIR_PA7,DIO_u8_DIR_PA6,DIO_u8_DIR_PA5,DIO_u8_DIR_PA4,DIO_u8_DIR_PA3,DIO_u8_DIR_PA2,DIO_u8_DIR_PA1,DIO_u8_DIR_PA0)
#define DIO_u8_DIR_PORTB  ConcPort(DIO_u8_DIR_PB7,DIO_u8_DIR_PB6,DIO_u8_DIR_PB5,DIO_u8_DIR_PB4,DIO_u8_DIR_PB3,DIO_u8_DIR_PB2,DIO_u8_DIR_PB1,DIO_u8_DIR_PB0)
#define DIO_u8_DIR_PORTC  ConcPort(DIO_u8_DIR_PC7,DIO_u8_DIR_PC6,DIO_u8_DIR_PC5,DIO_u8_DIR_PC4,DIO_u8_DIR_PC3,DIO_u8_DIR_PC2,DIO_u8_DIR_PC1,DIO_u8_DIR_PC0)
#define DIO_u8_DIR_PORTD  ConcPort(DIO_u8_DIR_PD7,DIO_u8_DIR_PD6,DIO_u8_DIR_PD5,DIO_u8_DIR_PD4,DIO_u8_DIR_PD3,DIO_u8_DIR_PD2,DIO_u8_DIR_PD1,DIO_u8_DIR_PD0)

#endif