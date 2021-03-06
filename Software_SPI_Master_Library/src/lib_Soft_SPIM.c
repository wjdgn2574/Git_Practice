/*
 ============================================================================
 Name        : lib_Soft_SPIM.c
 Author      : wjdgn2574
 Version     : 1.0
 Copyright   :
 Description : Software SPI Master(Using GPIO) Library Source File
 ============================================================================
*/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lib_Soft_SPIM.h"

// Input target MCU SPI Function's Header File
// Here

/*******************************************************************************
 * Private define
 ******************************************************************************/
#define DELAY 10

/*******************************************************************************
 * Private macro
 ******************************************************************************/

/*******************************************************************************
 * Private typedef
 ******************************************************************************/

/*******************************************************************************
 * Private variables
 ******************************************************************************/

/*******************************************************************************
 * Private function prototypes
 ******************************************************************************/

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Exported Functions
 ******************************************************************************/
void init_Soft_SPI_Master(void)
{
	/* Here input functions to init GPIO Pins */
	// CS	= Output Pin
	// SCL	= Output Pin
	// MOSI	= Output Pin
	// MISO	= Input Pin
}

void read_write_SPI_Master(unsigned char *tx, unsigned char *rx, int len_buffer)
{
	unsigned char wmask;
	unsigned char rmask;
	unsigned char data;
	unsigned char i, cnt;

	// Enable Clock Signal
	M_SCL_CLEAR;
	DELAY_MS(DELAY);

	// Enable Slave (Slave select active low)
	M_CS_CLEAR;
	DELAY_MS(DELAY);

	for(cnt=0; cnt<len_buffer; cnt++)
	{
		data = 0x80;
		wmask = 0x80;
		rmask = 0x80;

		for(i=0; i<8; i++)
		{
			// Write Byte
			if((tx[cnt]) & wmask)
			{
				M_MOSI_SET;
			}
			else
			{
				M_MOSI_CLEAR;
			}

			// Read Byte
			if(M_MISO_READ == 1)
			{
				data |= rmask;
			}
			else
			{
				data &= (~rmask);
			}

			DELAY_MS(DELAY);

			M_SCL_SET;
			DELAY_MS(DELAY);

			wmask >>= 1;
			rmask >>= 1;

			M_SCL_CLEAR;
		}

		M_MOSI_CLEAR;

		rx[cnt] = data;
	}

	M_SCL_CLEAR;
	M_MOSI_CLEAR;
	M_MISO_CLEAR;
	DELAY_MS(DELAY);

	// Disable Slave
	M_CS_SET;
	DELAY_MS(DELAY);
}
