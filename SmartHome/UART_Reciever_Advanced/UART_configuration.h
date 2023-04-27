#ifndef UART_Configuration_H
#define UART_Configuration_H

#define BAUD 9600
#define Rx_Complete_Interrupt_E_or_D Disable
#define Tx_Complete_Interrupt_E_or_D Disable
#define Data_Register_Empty_Interrupt_E_or_D Disable
#define Reciever_E_or_D    Enable
#define Transmitter_E_or_D  Enable
#define Character_Size _8_bits /*_5_bits,_6_bits,_7_bits,_8_bits*/
#define Uart_Mode Asynchronous /*Asynchronous,Synchronous*/
#define Parity_Mode Disable /*Even_parity,Odd_parity,Disabled*/
#define Stop_Bits_num  _1_bit   /*_2_bits,_1_bit*/

//for synchronous operation only
#define Clock_polarity  Rising_Falling /*Rising_Falling,Falling_Rising*/

#endif