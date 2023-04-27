
#include "STD_types.h"
#include "Bit_math.h"
#include "UART_private.h"
#include "UART_configuration.h"
#include "UART_interface.h"
#include <avr/interrupt.h>

static  void(*Recieve_Fptr)(void);
static  void(*Send_Fptr)(void);



void uart_initialization(unsigned long BAUDRATE){
	
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRA,U2X);
	#if Rx_Complete_Interrupt_E_or_D == Enable
	SetBit(UCSRB,RXCIE);
	#elif Rx_Complete_Interrupt_E_or_D == Disable
	ClearBit(UCSRB,RXCIE);
	#endif

	#if Tx_Complete_Interrupt_E_or_D == Disable
	SetBit(UCSRB,TXCIE);
	#elif Tx_Complete_Interrupt_E_or_D == Disable
	ClearBit(UCSRB,TXCIE);
	#endif


	#if Data_Register_Empty_Interrupt_E_or_D == Enable
	SetBit(UCSRB,UDRIE);
	#elif Data_Register_Empty_Interrupt_E_or_D == Disable
	ClearBit(UCSRB,UDRIE);
	#endif


	#if Reciever_E_or_D ==   Enable
	SetBit(UCSRB,RXEN);
	#elif Reciever_E_or_D  ==  Disable
	ClearBit(UCSRB,RXEN);
	#endif

	#if Transmitter_E_or_D == Enable
	SetBit(UCSRB,TXEN);
	#elif Transmitter_E_or_D  ==  Disable
	ClearBit(UCSRB,TXEN);
	#endif

	#if Character_Size == _5_bits
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRB,UCSZ2);
	ClearBit(UCSRC,UCSZ1);
	ClearBit(UCSRC,UCSZ0);
	#elif Character_Size == _6_bits
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRB,UCSZ2);
	ClearBit(UCSRC,UCSZ1);
	SetBit(UCSRC,UCSZ0);
	#elif Character_Size == _7_bits
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRB,UCSZ2);
	SetBit(UCSRC,UCSZ1);
	ClearBit(UCSRC,UCSZ0);
	#elif Character_Size == _8_bits
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRB,UCSZ2);
	SetBit(UCSRC,UCSZ1);
	SetBit(UCSRC,UCSZ0);
	#elif Character_Size == _9_bits
	SetBit(UCSRC,URSEL);
	SetBit(UCSRB,UCSZ2);
	SetBit(UCSRC,UCSZ1);
	SetBit(UCSRC,UCSZ0);
	#endif

	#if Uart_Mode == Asynchronous
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRC,UMSEL);
	#elif Uart_Mode == Synchronous
	SetBit(UCSRC,URSEL);
	SetBit(UCSRC,UMSEL);
	#endif


	#if Parity_Mode == Even_parity
	SetBit(UCSRC,URSEL);
	SetBit(UCSRC,UPM1);
	ClearBit(UCSRC,UPM0);
	#elif Parity_Mode == Odd_parity
	SetBit(UCSRC,URSEL);
	SetBit(UCSRC,UPM1);
	SetBit(UCSRC,UPM0);
	#elif Parity_Mode == Disable
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRC,UPM1);
	ClearBit(UCSRC,UPM0);
	#endif

	#if Stop_Bits_num == _2_bits   /*_2_bits,_1_bit*/
	SetBit(UCSRC,URSEL);
	SetBit(UCSRC,USBS);
	#elif Stop_Bits_num == _1_bit
	SetBit(UCSRC,URSEL);
	ClearBit(UCSRC,USBS);
	#endif


	/*set baudrate**/
	
	    UBRRL = BAUD_PRESCALE;							/* Load UBRRL with lower 8 bit of prescale value */
	 	UBRRH = (BAUD_PRESCALE >> 8);					/* Load UBRRH with upper 8 bit of prescale value */
	
}

void RX_Complete_Interrupt_Enable(void){
	
	SetBit(UCSRB,RXCIE);
	
}

void TX_Complete_Interrupt_Enable(void){
	
	SetBit(UCSRB,TXCIE);
	
}



void send_uart(u8 uart_sdata){
	
	
	while(GetBit(UCSRA,UDRE)==0);
	
	UDR=uart_sdata;
	
}
u8 recieve_uart(){
	
	while(GetBit(UCSRA,RXC)==0);
	
	return UDR;
	
	
}


void Send_UART_NoBlock(u8 uart_sdata){
	
	UDR=uart_sdata;
	
}
u8 Recieve_UART_NoBlock(){
	
	return UDR;
}

void Recieve_SetCallBack(void(*Local_Fptr)(void)){
	
	Recieve_Fptr=Local_Fptr;
	
}


void Send_SetCallBack(void(*Local_Fptr)(void)){
	
	Send_Fptr=Local_Fptr;
	
}




ISR(USART_RXC_vect){
	if (Recieve_Fptr!=NULLPTR)
	{
		Recieve_Fptr();
	}
}


ISR(USART_TXC_vect){

	if (Send_Fptr!=NULLPTR)
	{
		Send_Fptr();
	}
}





