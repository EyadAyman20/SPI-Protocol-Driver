
#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI.h"

void SPI_voidMaster_Init(void)
{
	//mosi  //B3
	SET_BIT(DDRB,3);
	//miso // B4
	CLR_BIT(DDRB,4);
	//sck  B5
	SET_BIT(DDRB,5);
	//ss  B2 INTERNAL PULL RESISTANCE
	SET_BIT(DDRB,2);  //OUTPUT
	SET_BIT(PORTB,2); // PULL UP

/*REG*/
/*SPCR*/
//Bit 7 – SPIE: SPI Interrupt Enable
CLR_BIT(SPCR,7);   
//• Bit 5 – DORD: Data Order  //LSB 1st
SET_BIT(SPCR,5);
//• Bit 4 – MSTR: Master/Slave Select
SET_BIT(SPCR,4); // master
//• Bit 3 – CPOL: Clock Polarity  //high
SET_BIT(SPCR,3);
//• Bit 2 – CPHA: Clock Phase  //leading ==setup //  trailing sample
SET_BIT(SPCR,2);
//• Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0   /64
CLR_BIT(SPCR,0);
SET_BIT(SPCR,1);
CLR_BIT(SPSR,0);  //spi2x
// Bit 6 – SPE: SPI Enable
SET_BIT(SPCR,6);  

}
void SPI_voidSlave_Init(void)
{
	//mosi  //B3
	CLR_BIT(DDRB,3);
	//miso // B4
	SET_BIT(DDRB,4);
	//sck  B5
	CLR_BIT(DDRB,5);
	//ss  B2 INTERNAL PULL RESISTANCE
	CLR_BIT(DDRB,2);  //input

	/*REG*/
	/*SPCR*/
	//Bit 7 – SPIE: SPI Interrupt Enable
	CLR_BIT(SPCR,7);
	//• Bit 5 – DORD: Data Order  //LSB 1st
	SET_BIT(SPCR,5);
	//• Bit 4 – MSTR: Master/Slave Select
	CLR_BIT(SPCR,4); // slave
	//• Bit 3 – CPOL: Clock Polarity  //high
	SET_BIT(SPCR,3);
	//• Bit 2 – CPHA: Clock Phase  //leading ==setup //  trailing sample
	SET_BIT(SPCR,2);
	// Bit 6 – SPE: SPI Enable
	SET_BIT(SPCR,6);
}
u8 SPI_u8Transceive(u8 data)
{
SPDR=data;

while(GET_BIT(SPSR,7) == 0);  ///

return SPDR;
}

u8 SPI_u8Receive(void)
{
	
	while(GET_BIT(SPSR,7) == 0);

	return SPDR;
	
}
