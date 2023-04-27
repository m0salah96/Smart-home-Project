#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UDR   (* (  volatile u8 * ) 0x2C )
#define UCSRA (* (  volatile u8 * ) 0x2B )
#define UCSRB (* (  volatile u8 * ) 0x2A )
#define UCSRC (* (  volatile u8 * ) 0x40 )
#define UBRRH (* (  volatile u8 * ) 0x40 )
#define UBRRL (* (  volatile u8 * ) 0x29 )

#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR 	3
#define PE 		2
#define U2X 	1
#define MPCM 	0

#define RXCIE 	7
#define TXCIE 	6
#define UDRIE 	5
#define RXEN 	4
#define TXEN 	3
#define UCSZ2 	2
#define RXB8 	1
#define TXB8 	0

#define URSEL 	7
#define UMSEL 	6
#define UPM1 	5
#define UPM0 	4
#define USBS 	3
#define UCSZ1 	2
#define UCSZ0 	1
#define UCPOL 	0

#define Enable 1
#define Disable 0


#define _1_bit   1
#define _2_bits  2
#define _5_bits  5
#define _6_bits  6
#define _7_bits  7
#define _8_bits  8
#define _9_bits  9
#define Asynchronous  1 
#define Synchronous   0
#define Even_parity   1 
#define Odd_parity    0


#define Rising_Falling   1
#define Falling_Rising   0

#endif