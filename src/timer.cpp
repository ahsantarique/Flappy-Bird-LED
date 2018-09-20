// initialize timer, interrupt and variable
#include <avr/io.h>
#include <stdlib.h>
#include "graph.cpp"
#include "bird.cpp"
#include "slideTunnel.cpp"

void timer1_init()
{
	// set up timer with prescaler = 64 and CTC mode
	TCCR1B |= (1 << WGM12)|(1 << CS11);

	// initialize counter
	TCNT1 = 0;

	// initialize compare value
	OCR1A = 2000;

	// enable compare interrupt
	TIMSK |= (1 << OCIE1A);

	// enable global interrupts
	sei();
}



// this ISR is fired whenever a match occurs
// hence, toggle led here itself..
unsigned char cnt = 0;
int u,l;
int flag =0;
int delay=0;
ISR (TIMER1_COMPA_vect){
	cnt++;
	// slide tunnel
	if(cnt%(20-speed)==0){
		birdHeight++;

		slideTunnel();
		if(flag>0 && flag<4){
			initiateTunnel(u,l);
			flag++;
		}
		else{
			flag = 0;
		}
	}
	
	if(cnt>=230){
		u=rand()%8+2;
		if(u>7) u = 1;
		l=u+6+rand()%5;
		if(l>14) l=14;
		if(l-u>5) u=l-5;


		initiateTunnel(u,l);
		cnt=0;
		flag=1;
	}
	if(PINA && !delay){
		up=true;
		birdHeight--;
		delay++;
	}
	if(delay) delay++;
	if(delay>10){
		delay=0;
	}
}


