/*
 ============================================================================
 Name        : lib_Soft_SPIM.h
 Author      : wjdgn2574
 Version     : 1.0
 Copyright   :
 Description : Software SPI Master(Using GPIO) Library Example for nRF51822
 ============================================================================
*/

#ifndef LIB_SOFT_SPIM_H_
#define LIB_SOFT_SPIM_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

// Input target MCU SPI Function's Header File
#include "custom_board.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

/*******************************************************************************
 * Exported defines
 ******************************************************************************/
#define M_SPI_CS		GPIO_PIN_16	// SPI Master - SCK
#define M_SPI_SCK		GPIO_PIN_17	// SPI Master - MISO
#define M_SPI_MISO		GPIO_PIN_18	// SPI Master - MOSI
#define M_SPI_MOSI		GPIO_PIN_19	// SPI Master - CS

/*******************************************************************************
 * Exported macros
 ******************************************************************************/
#define M_CS_SET		/* Here input function of bit 1 for CS */
#define M_CS_CLEAR		/* Here input function of bit 0 for CS */
#define M_SCL_SET		/* Here input function of bit 1 for SCL */
#define M_SCL_CLEAR		/* Here input function of bit 0 for SCL */
#define M_MOSI_SET		/* Here input function of bit 1 for MOSI */
#define M_MOSI_CLEAR	/* Here input function of bit 0 for MOSI */
#define M_MISO_SET		/* Here input function of bit 1 for MISO */
#define M_MISO_CLEAR	/* Here input function of bit 0 for MISO */

#define M_MOSI_READ		/* Here input function of reading bit for MOSI */
#define M_MOSI_WRITE	/* Here input function of writing bit for MOSI */
#define M_MISO_READ		/* Here input function of reading bit for MISO */
#define M_MISO_WRITE	/* Here input function of writing bit for MISO */

#define M_DELAY_MS(n)	/* Here input function of delay ms */

/*******************************************************************************
 * Exported types
 ******************************************************************************/

/*******************************************************************************
 * Exported constants
 ******************************************************************************/

/*******************************************************************************
 * Exported functions
 ******************************************************************************/
void init_Soft_SPI_Master(void);
void read_write_SPI_Master(unsigned char *tx, unsigned char *rx, int len_buffer);

#endif /* LIB_SOFT_SPIM_H_ */
