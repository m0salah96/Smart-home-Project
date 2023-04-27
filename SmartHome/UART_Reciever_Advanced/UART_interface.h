#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


#define F_CPU 16000000UL
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)
void uart_initialization(unsigned long BAUDRATE);
void send_uart(u8 uart_sdata);
u8 recieve_uart();
void USART_Init()	;
void RX_Complete_Interrupt_Enable(void);
void TX_Complete_Interrupt_Enable(void);
void Send_UART_NoBlock(u8 uart_sdata);
u8 Recieve_UART_NoBlock(void);
void Recieve_SetCallBack(void(*Local_Fptr)(void));
void Send_SetCallBack(void(*Local_Fptr)(void));
#endif
