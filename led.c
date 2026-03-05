#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Set direction register output
  DDRD = DDRD | (1 << PD2);

  while(1) {
    PORTD = PORTD | (1 << PD2);
    _delay_ms(100);

    PORTD = PORTD & ~(1 << PD2);

    _delay_ms(100);
  }
}
