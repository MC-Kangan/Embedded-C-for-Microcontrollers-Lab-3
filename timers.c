#include <xc.h>
#include "timers.h"

/************************************
 * Function to set up timer 0
************************************/
void Timer0_init(void)
{
    T0CON1bits.T0CS=0b010; // Fosc/4 (See datasheet P354)
    T0CON1bits.T0ASYNC=1; // see datasheet errata - needed to ensure correct operation when Fosc/4 used as clock source
    T0CON1bits.T0CKPS=0b1000; // 1:256 (pre-scaler = 1 / 4 * 64 * 10^6 / 65535 = 244.24 approx to 256)
    T0CON0bits.T016BIT=1;	//16 bit mode	
	
    // it's a good idea to initialise the timer registers so we know we are at 0
    TMR0H = 65535;            //write High reg first, update happens when low reg is written to // 255 in 8 bit mode (from instructions)
    TMR0L = 0;
    T0CON0bits.T0EN=1;	//start the timer
    
    
}

/************************************
 * Function to return the full 16bit timer value
 * Note TMR0L and TMR0H must be read in the correct order, or TMR0H will not contain the correct value
************************************/
unsigned int get16bitTMR0val(void)
{
    TMR0L; // Read TMR0L first to get the updated value for TMR0H
    return TMR0H; // Return TMR0H, which contains 8 most significant figures
   
}
