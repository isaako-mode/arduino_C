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
  DDRB = 0x0F;

   // Set direction register input
  DDRD = DDRD & ~(1 << PD4);
   
   // Read to track if the button is pressed
  uint8_t read = 0x00;
  uint8_t is_pressed = 0;
  uint8_t led_dir = 0;
  
  while(1) {
    _delay_ms(500);
    read = PIND & (1 << PD4);

    if(read) {
      is_pressed = 1;
    }

    _delay_ms(500);

    if(is_pressed) {
      PORTB = 0X0F;
      _delay_ms(500);
      
      PORTB = 0X00;
      _delay_ms(500);

      PORTB = 0X0F;
      _delay_ms(500);

      PORTB = 0X00;
      _delay_ms(500);

      PORTB = 0X0F;
      _delay_ms(500);

      PORTB = 0X00;
      _delay_ms(500);
    }

    if(PORTB == 0X00) {
      PORTB = 0X01;
    }
    
    if(PORTB == 0x01) {
      led_dir = 0;
    }

    if(PORTB == 0x08) {
      led_dir = 1;
    }

    if(led_dir == 0) {
      PORTB *= 2;
    }

    if(led_dir == 1 && PORTB != 0X01) {
      PORTB /= 2;
    }

    is_pressed = 0;

  }
  
}

