#include "rf_module.h"

#include <wiringPi.h>

/** Send a single byte
 * This function uses a fixed bitrate
 * of 8192 bps ( = 1 kiB per second)
 * 
 * The least significant bit is transmitted first
 */
static inline void tx_byte(unsigned char byte, unsigned int pin) {
	const unsigned int delayDuration = 1000000 / 8192;
	int i;
	for (i = 0; i < 8; i++) {
		if (byte & 0x01) {
			digitalWrite(pin, HIGH);
	        } else {
	 		digitalWrite(pin, LOW);
		}
		byte = byte >> 1;
		delayMicroseconds(delayDuration);
	}
}

int rf_default_simple_tx(unsigned char* buffer, size_t num_bytes, unsigned int pin) {
	size_t i;
	int num_transmitted = 0;
	for (i = 0; i < num_bytes; i++) {
		tx_byte(buffer[i], pin);	
		num_transmitted++;
	}
	return num_transmitted;
}
