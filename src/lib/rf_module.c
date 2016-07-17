#include "rf_module.h"

rf_simple_receiver_t rf_make_simple_receiver(unsigned int pin, rf_rx_fnc_t receive) {
	rf_simple_receiver_t rx = {
		.data_pin = pin,
		.receive = receive
	};
	return rx;
}

rf_simple_transmitter_t rf_make_simple_transmitter(unsigned int pin, rf_tx_fnc_t transmit) {
	rf_simple_transmitter_t tx = {
		.data_pin = pin,
		.transmit = transmit
	};
	return tx;
}
