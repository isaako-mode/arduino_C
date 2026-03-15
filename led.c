#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

int main(void) {

  /* PINS:

     LEDs:
     
     PB0
     PB1
     PB2
     PB3

     BUTTON:
     PD4
   */

  
  // Set direction register output
  DDRB = 0x0F;

   // Set direction register input
  DDRD = DDRD & ~(1 << PD4);
   
   // Read to track if the button is pressed
  uint8_t read = 0x00;
  uint8_t is_pressed = 0;
  uint8_t direction = 0;

  PORTB |= (1 << PB0);

  while(1) {
    _delay_ms(50);
    read = PIND & (1 << PD4);

    if(read) {
      is_pressed = 1;
    }

    _delay_ms(500);

    //Blink 3 times when button is pressed
    if(is_pressed) {
      
      for(int i=0; i<3; i++) {
	PORTB = 0x0F;
	_delay_ms(500);

	PORTB = 0x00;
       _delay_ms(500);
      }

      PORTB = 0x01;
    }

    if (PORTB == 0x08) {
      direction = 0;
    }

    
    if (PORTB == 0x01) {
      direction = 1;
    }


    if(direction) {
      
      PORTB <<= 1;
    }
    else {
      
      PORTB >>= 1;
    }

    is_pressed = 0;

  }
  
}

