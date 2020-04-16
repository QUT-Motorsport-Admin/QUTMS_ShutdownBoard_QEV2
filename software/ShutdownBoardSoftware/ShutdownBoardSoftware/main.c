/*
 * ShutdownBoardSoftware.c
 *
 * Created: 7/09/2019 9:41:05 PM
 * Author : Jonn
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

uint8_t init(void) {
	// Set Up Ports
	//		 LED B			  LED A
	DDRD = (1 << PORTD7) || (1 << PORTD6);
	PORTD = (1 << PORTD7) || (1 << PORTD6);
	return 0;
}

uint8_t mux_setCh(uint8_t channel) {
	// MUX Channels
	// Ch A => Pin 35, PA2
	// Ch B => Pin 34, PA3
	// Ch C => Pin 33, PA4
	// Ch D => Pin 32, PA5
	
	// Input checking
	if (channel >= 15) channel = 15;
	
	PORTA = channel << 2; // Since the only other channel is SHDN_SENSE on PA0, we can always set to 0 and not have a problem
	_delay_us(1); // Waiting 1us (1/100th of a ms), to let the MUX switch over. MUX datasheet max switch time is 700ns = 1us * 0.7
	return channel;
}

int main(void) {
	while (1) {
		LED_A_ON;
		LED_B_OFF;
		_delay_ms(500);
		LED_A_OFF;
		LED_B_ON;
		_delay_ms(500);
	}
}

