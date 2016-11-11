#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>

//for a 26MHz Crystal:
#define CC2510_BAUD_E_115200 12
#define CC2510_BAUD_E_57600  11
#define CC2510_BAUD_M_115200 34
#define CC2510_BAUD_M_57600  34

//use 155200 baud
#define UART_BAUD_M CC2510_BAUD_M_115200
#define UART_BAUD_E CC2510_BAUD_E_115200

void uart_init(void);

union hal_uart_config_t{
  uint8_t byte;
  struct{
        uint8_t START : 1; //start bit level
        uint8_t STOP  : 1; //stop bit level
        uint8_t SPB   : 1; //stop bits (0=1, 1=2)
        uint8_t PARITY: 1; //parity (on/off)
        uint8_t BIT9  : 1; //9 bit mode
        uint8_t D9    : 1; //9th bit level or parity type
        uint8_t FLOW  : 1; //flow control
        uint8_t ORDER : 1; //data bit order (LSB or MSB first)
  } bit;
};

uint8_t uart_getc(void);
void uart_putc(uint8_t c);

/*
static void hal_uart_set_mode(__xdata union hal_uart_config_t *cfg);

#define DEBUG_ISR(void) hal_uart_tx_interrupt(void) __interrupt UTX0_VECTOR
#define HAL_UART_ISR_FLAG_SET() (1)
#define HAL_UART_ISR_CLEAR_FLAG() { UTX0IF = 0; }
#define HAL_UART_ISR_DISABLE() { IEN2 &= ~(IEN2_UTX0IE); }
#define HAL_UART_TX_DATA(data) { U0DBUF = data; }
*/


#endif // __UART_H__
