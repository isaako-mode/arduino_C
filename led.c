#include <avr/io.h>
#include <util/delay.h>

/* void IOSetDir(volatile uint8_t *ddr, uint8_t pin, uint8_t mode) { */

/*   if(mode) { */
/*     *ddr |= (1 << pin); */
/*   } */
/*   else { */
/*     *ddr &= ~(1 << pin); */
/*   } */
/* } */

int main(void) {

  /* PINS:
     PB0
     PB1
     PB2
     PB3
   */

  /* IOSetDir((volatile uint8_t*)_SFR_MEM_ADDR(DDRB), PB0, 1); */
  /* IOSetDir((volatile uint8_t*)_SFR_MEM_ADDR(DDRB), PB1, 1); */
  /* IOSetDir((volatile uint8_t*)_SFR_MEM_ADDR(DDRB), PB2, 1); */
  /* IOSetDir((volatile uint8_t*)_SFR_MEM_ADDR(DDRB), PB3, 1); */
  
  // Goal: toggle pin 8x
  // Set direction register output
   DDRB = DDRB | (1 << PB0);
   DDRB = DDRB | (1 << PB1);
   DDRB = DDRB | (1 << PB2);
   DDRB = DDRB | (1 << PB3);

   // set direction register input
   DDRD = DDRD & ~(1 << PD4);
   
  // turn pin 8 ON
   int read = 0x00;
   
  while(1) {
    read = PIND & (1 << PD4);
    
    if(read) {

      //turn on all pins
      PORTB |= (1 << PB0);      
      PORTB |= (1 << PB1);      
      PORTB |= (1 << PB2);
      PORTB |= (1 << PB3);

      continue;
    }
    
    // toggle the pin
    PORTB |= (1 << PB0);
    _delay_ms(100);
    PORTB |= (1 << PB1);
    _delay_ms(100);
    PORTB |= (1 << PB2);
    _delay_ms(100);
    PORTB |= (1 << PB3);
    _delay_ms(100);
    //PORTB ^= (1 << PB0);

    PORTB &= ~(1 << PB0);
     _delay_ms(100);
    PORTB &= ~(1 << PB1);
     _delay_ms(100);
    PORTB &= ~(1 << PB2);
     _delay_ms(100);
    PORTB &= ~(1 << PB3);

    _delay_ms(100);
    PORTB |= (1 << PB3);
    _delay_ms(100);
    PORTB |= (1 << PB2);
    _delay_ms(100);
    PORTB |= (1 << PB1);
    _delay_ms(100);
    PORTB |= (1 << PB0);


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

