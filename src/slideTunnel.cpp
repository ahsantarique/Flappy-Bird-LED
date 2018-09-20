#include <avr/io.h>

char speed = 1;


void slideTunnel(){
	eraseBird();
	for(int i = 0; i < 16; i++){
		graph[i] <<=1;
	}
	drawBird();
}

void initiateTunnel(int u, int l){
	for(int i =0; i < 16;i++){
		if(i>u&&i<l) continue;
		set(i,0);
	}
}