#include <avr/io.h>

char speed = 1;


void slideTunnel(){
	for(int i = 0; i < 16; i++){
		graph[i] <<=1;
	}
}

void initiateTunnel(int u, int l){
	for(int i =0; i < 16;i++){
		if(i>u&&i<l) continue;
		set(i,0);
	}
}