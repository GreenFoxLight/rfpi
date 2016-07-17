#include <wiringPi.h>
#include "rf_module.h"

int main(void) {
	wiringPiSetup();

	pinMode(0, OUTPUT);
	unsigned char data[8192];
	for (int i = 0; i < 8192; i++) {
		data[i] = (i % 2) * 255;
	}
	rf_simple_transmitter_t tx = rf_make_simple_tx(0);
	tx.transmit(data, sizeof(data), tx.data_pin);	

	return 0;
}
