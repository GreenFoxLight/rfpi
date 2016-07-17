#ifndef RFPI_RF_MODULE_H
#define RFPI_RF_MODULE_H

#include <stddef.h>

typedef int (*rf_rx_fnc_t)(unsigned char*, size_t, unsigned int);

typedef int (*rf_tx_fnc_t)(unsigned char*, size_t, unsigned int);

/** \brief A simple receiver with 1 data pin
 * (For example common 433 MHz modules)
 */
typedef struct rf_simple_receiver {
	unsigned int data_pin;
	rf_rx_fnc_t receive;	
} rf_simple_receiver_t;

/** \brief A simple transmitter with 1 data pin
 * (For example common 433 MHz modules)
 */
typedef struct rf_simple_transmitter {
	unsigned int data_pin;
	rf_tx_fnc_t transmit;
} rf_simple_transmitter_t;

/************************************************
 *     Constructor Functions                    *
 ************************************************/

#define rf_make_simple_rx(pin) (rf_make_simple_receiver(pin, rf_default_simple_rx))

/** \brief Create handler for a simple receiver
 * using custom receive function
 *
 * \param pin wiringPi pin number of the receivers data pin
 * \param receive custom receive function
 */
rf_simple_receiver_t rf_make_simple_receiver(unsigned int pin, rf_rx_fnc_t receive);

#define rf_make_simple_tx(pin) (rf_make_simple_transmitter(pin, rf_default_simple_tx))

/** \brief Create handler for a simple transmitter
 * using custom transmit function
 *
 * \param pin wiringPi pin number of the transmitters data pin
 * \param transmit custom transmit function
 */
rf_simple_transmitter_t rf_make_simple_transmitter(unsigned int pin, rf_tx_fnc_t transmit);

/**********************************************
 * Default transmit / receive functions       *
 **********************************************/

int rf_default_simple_rx(unsigned char* buffer, size_t max_bytes, unsigned int pin);

int rf_default_simple_tx(unsigned char* buffer, size_t num_bytes, unsigned int pin);

#endif // RFPI_RF_MODULE_H
