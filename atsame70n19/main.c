#include <atmel_start.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	const uint8_t LED_1_PIN = PIN_PD26;
	const uint8_t LED_2_PIN = PIN_PD25;
	const uint8_t LED_3_PIN = PIN_PD24;


	gpio_set_pin_function(LED_1_PIN, GPIO_PIN_FUNCTION_A);
	gpio_set_pin_function(LED_2_PIN, GPIO_PIN_FUNCTION_A);
	gpio_set_pin_function(LED_3_PIN, GPIO_PIN_FUNCTION_A);



	// Start by setting all gpio pins as input (high-z)
	// gpio_set_port_direction(GPIO_PORTA, 0xFFFFFFFF, GPIO_DIRECTION_OFF);
	// gpio_set_port_direction(GPIO_PORTB, 0xFFFFFFFF, GPIO_DIRECTION_OFF);
	// gpio_set_port_direction(GPIO_PORTC, 0xFFFFFFFF, GPIO_DIRECTION_OFF);
	// gpio_set_port_direction(GPIO_PORTD, 0xFFFFFFFF, GPIO_DIRECTION_OFF);
	// gpio_set_port_direction(GPIO_PORTE, 0xFFFFFFFF, GPIO_DIRECTION_OFF);

	// Set output programming LED level
	gpio_set_pin_direction(LED_1_PIN, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(LED_1_PIN, false);

	while (1) {
		//delay


		//toggle output programming LED
	}
}
