/*
 * Uart.c
 *
 * Created: 9/21/2026 2:05:50 PM
 * Author : Eyad.Ayman
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"

int main(void)
{
	UART_Init();
	UART_Send(3);
    /* Replace with your application code */
    while (1) 
    {
    }
}

