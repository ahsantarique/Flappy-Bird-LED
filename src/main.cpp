/*
 * GccApplication2.cpp
 *
 * Created: 5/25/2016 3:25:06 AM
 * Author : Ahsan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.cpp"
#include "startscreen.cpp"



int score = 0;

int main(void)
{
	// connect led to pin PC0
    DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	
	DDRA = 0x0; //need to change that later;


	// initialize timer
	timer1_init();

	// loop forever
	
	while(1)
	{
		// do nothing
		// whenever a match occurs, ISR is fired
		// toggle the led in the ISR itself
		// no need to keep track of any flag bits here
		// done!
		 if(!gameover)draw();
		 else startScreen();
// 		if(PINA && !delay){
// 			up=true;
// 			birdHeight--;
// 			delay++;
// 		}
// 		if(delay) delay++;
// 		if(delay>600){
// 			delay=0;
// 		}
	}
	return 0;
}

// pb row, pc pd col
// int main(void)
// {
//     /* Replace with your application code */
//     DDRB = 0xFF;
// 	DDRC = 0xFF;
// 	DDRD = 0xFF;
// 	
// 
// 
// 	while (1) 
//     {
// 			startScreen();
// 			//slideTunnel();
// 			
// 			while(1){
// 				if(r>15) r=0;
// 				while(1){
// 					int cnt = mx*10;
// 					PORTB=r;
// 					c=c<<1;
// 					unsigned char x = (c&255);
// 					PORTC=x;
// 					x = c>>8;
// 					PORTD=x;
// 					while(cnt--){;}
// 					if(c==0){
// 						c=1;
// 						break;
// 					}
// 				}
// 				r++;
// 			}
//     }
// }

