/*
 * Spi App M.c
 *
 * Created: 9/21/2026 2:00:09 PM
 * Author : Eyad.Ayman
 */ 

// Master

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI.h"

int main(void)
{
	SPI_voidMaster_Init()	;
    /* Replace with your application code */
    while (1) 
    {
		SPI_u8Transceive(2);
    }
}

