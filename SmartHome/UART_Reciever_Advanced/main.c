/*================================================*/
/*===================UART RECIEVER================*/
/*===================Mohmamed salah===============*/
/*==================25April 2023==================*/
/*================================================*/






#include <avr/io.h>
#define F_CPU 16000000UL
#include "avr/delay.h"
#include <avr/interrupt.h>
#include "STD_types.h"
#include "Bit_math.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"
u8 data='n';


typedef enum status{
	
	ON,
	OFF,
	undefined
	}l_status;






int main(void)
{   

	DIO_Void_Init();
	LCD_Void_Init();
	/*USART_Init(9600);*/
	uart_initialization(9600);
    l_status lamp_status=undefined;
	while (1)
	{    
		
		//display data
		 LCD_voidSetCursor(0,0);
		 LCD_voidSendString("status=");
		 LCD_voidSetCursor(0,9);
		 data=recieve_uart();
		 

		 if (data=='1')
		 {
			 lamp_status=ON;
		 }else if (data=='2')
		 {
			 lamp_status=OFF;
		 }
		 //update lamp status
		 
     			 if (lamp_status==ON)
     			 {
	     			 DIO_Void_SetPin(DIO_U8_PORTB,DIO_U8_Pin0);
					 LCD_voidSendString("ON "); 
     			 }else if (lamp_status==OFF)
     			 {
	     			 DIO_Void_ClearPin(DIO_U8_PORTB,DIO_U8_Pin0);
					  LCD_voidSendString("OFF");
     			 }	 

		 
		
	}


	
}
