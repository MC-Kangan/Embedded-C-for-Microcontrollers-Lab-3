// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
//#include "LEDarray.h"
#include "interrupts.h"
#include "comparator.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


void main(void) {
	//call your initialisation functions to set up the hardware modules

     // setup pin for output (connected to LED2 - RH3)
    LATHbits.LATH3=0;   //set initial output state - LATx registers (output latch)
    TRISHbits.TRISH3=0; //set TRIS value for pin (output) - TRISx registers (data direction)
    
    Interrupts_init(); // Interrupt
    Comp1_init();// Comparator
    
    while (1) {
		//Sleep();
    }
}