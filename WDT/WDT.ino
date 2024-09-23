#include <avr/io.h>
#include <util/delay.h>
//#include <util/sleep.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#define F_CPU 16000000UL
int counter = 0;

int main(void){

    cli();
    wdt_reset();
    WDTCSR |= (1 << WDCE) | (1<< WDE);
    WDTCSR = (1 << WDP2) | (1 << WDP1) | (1 << WDIE); //CONFIGURANDO BASES DE TEMPO DE 1s
    sei();
    DDRD |=(1<<7);
    DDRD |=(1<<6);

    PORTD &= ~(1<<7);

    while(1){
      PORTD |= (1<<7);
      _delay_ms(2000);
    }

}

ISR(WDT_vect){
  PORTD ^= (1<<6);
  wdt_reset();

}