/*
 ============================================================================
 Name        : lib_Soft_SPIM_nRF51822.h
 Author      : wjdgn2574
 Version     : 1.0
 Copyright   :
 Description : Software SPI Master(Using GPIO) Library Example for nRF51822
 ============================================================================
*/

#ifndef LIB_SOFT_SPIM_NRF51822_H_
#define LIB_SOFT_SPIM_NRF51822_H_

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
#define M_CS_SET		nrf_gpio_pin_set(SPI_CS_M0)
#define M_CS_CLEAR		nrf_gpio_pin_clear(SPI_CS_M0)
#define M_SCL_SET		nrf_gpio_pin_set(SPI_SCK_M0)
#define M_SCL_CLEAR		nrf_gpio_pin_clear(SPI_SCK_M0)
#define M_MOSI_SET		nrf_gpio_pin_set(SPI_MOSI_M0)
#define M_MOSI_CLEAR	nrf_gpio_pin_clear(SPI_MOSI_M0)
#define M_MISO_SET		nrf_gpio_pin_set(SPI_MISO_M0)
#define M_MISO_CLEAR	nrf_gpio_pin_clear(SPI_MISO_M0)

#define M_MOSI_READ		nrf_gpio_pin_read(SPI_MISO_M0)
#define M_MISO_READ		nrf_gpio_pin_read(SPI_MOSI_M0)

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

#endif /* LIB_SOFT_SPIM_NRF51822_H_ */
