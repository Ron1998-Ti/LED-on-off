#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR|=BIT0; // El bit 0 del puerto 1 se configura como salida, el resto como entrada
	P1SEL=0;     // El puerto se configura como entrada salida
	P1REN|=BIT1; // Se habilitan las resistencias en el bit 1 del puerto 1
	P1OUT|=BIT1; // La resistencia en el bit 1 del puerto 1 pullup, la salida del bit 0 está en bajo

	while (1) {
	        if ((P1IN & BIT1)==0)      // Si P1.1 se pulsa
	            P1OUT |=BIT0;         // bit P1.0 a 1 (enciende LED1)
	        else                      // sino
	        P1OUT &= ~BIT0;           // bit P1.0 a 0 (apaga LED1)
	    }
}

