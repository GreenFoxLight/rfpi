#include "rf_module.h"

#include <wiringPi.h>

/* This functions receives at a fixed bitrate of 8192 bps (= 1kiB per second)
 */
static inline void rx_byte(unsigned char* buf, unsigned int pin) {
	const int delayDuration = 1000000 / 8192;
	const int lowThreshold = 50;	/* everything below lowThreshold is a 1 bit */
	const int highThreshold = 70;   /* everything above highThreshold is a 0 bit */
	int i, val;
	*buf = 0;
	for (i = 0; i < 8; i++) {
		val = analogRead(pin);
		if (val < lowThreshold) {
			*buf |= 1 << i;
			delayMicroseconds(delayDuration);
		} else if (val > highThreshold) {
			/* *buf |= 0 << i; */
			delayMicroseconds(delayDuration);
		} else {
			i--; // discard noise and try again
		}
	}
}

int rf_default_simple_rx(unsigned char* buffer, size_t max_bytes, unsigned int pin) {
	size_t i;
	int num_received;
	for (i = 0; i < max_bytes; i++) {
		rx_byte(buffer + i, pin);
		num_received++;
	}
	return num_received;
}
