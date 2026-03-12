#include <avr/io.h>
#include <util/delay.h>

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
   DDRB = DDRB | (1 << PB0);
   DDRB = DDRB | (1 << PB1);
   DDRB = DDRB | (1 << PB2);
   DDRB = DDRB | (1 << PB3);

   // Set direction register input
   DDRD = DDRD & ~(1 << PD4);
   
   // Read to track if the button is pressed
   int read = 0x00;
   
  while(1) {
    
    read = PIND & (1 << PD4);
    
    if(read) {

      //turn on all pins when button is pressed
      PORTB |= (1 << PB0);      
      PORTB |= (1 << PB1);      
      PORTB |= (1 << PB2);
      PORTB |= (1 << PB3);

      continue;
    }
    
    // Turn on the LEDs one by on
    PORTB |= (1 << PB0);
    _delay_ms(100);
    PORTB |= (1 << PB1);
    _delay_ms(100);
    PORTB |= (1 << PB2);
    _delay_ms(100);
    PORTB |= (1 << PB3);
    _delay_ms(100);

    // Turn on the LEDs one by on
    PORTB &= ~(1 << PB0);
     _delay_ms(100);
    PORTB &= ~(1 << PB1);
     _delay_ms(100);
    PORTB &= ~(1 << PB2);
     _delay_ms(100);
    PORTB &= ~(1 << PB3);

    // Turn off the LEDs one by one going the opposite way
    _delay_ms(100);
    PORTB |= (1 << PB3);
    _delay_ms(100);
    PORTB |= (1 << PB2);
    _delay_ms(100);
    PORTB |= (1 << PB1);
    _delay_ms(100);
    PORTB |= (1 << PB0);

    // Turn on the LEDs one by on
    _delay_ms(100);
    PORTB &= ~(1 << PB3);
    _delay_ms(100);
    PORTB &= ~(1 << PB2);
    _delay_ms(100);
    PORTB &= ~(1 << PB1);
    _delay_ms(100);
    PORTB &= ~(1 << PB0);
    _delay_ms(100);

    
   }
  
}

