﻿const int mx=10000;

void startScreen(){
	char dump[][2]={0x07,0x80,0x04,0,0x04,0,0x07,0,0x04,0,0x04,0,0x04,0,0,0,0b01000100,0b00000010,0b01000000,0b00000010,0b01110101,0b01101110,0b01010100,0b10001010,0b01110100,0b10001110};
	char alphabet[][7][2]= {0x07,0x80,0x04,0,0x04,0,0x07,0,0x04,0,0x04,0,0x04,0,
		0x06,0,0x06,0,0x06,0,0x06,0,0x06,0,0x07,0xE0,0x07,0xE0,
		0x07,0xC0,0x04,0x40,0x04,0x40,0x07,0xC0,0x04,0x40,0x04,0x40,0,0,
		0x07,0xC0,0x04,0x40,0x04,0x40,0x07,0xC0,0x04,0,0x04,0,0x04,0,
		0x03,0xE0,0x02,0x20,0x02,0x20,0x03,0xE0,0x02,0,0x02,0,0x02,0,
		0x08,0x40,0x08,0x40,0x04,0x80,0x07,0x80,0x03,0x0,0x03,0x0,0x03,0x0
	};
	int cnt;
	int cur=1;
	while(1){
// 		if(PINA){
// 			gameover = true;
// 			int cnt = 1000;
// 			while(cnt--){
// 
// 			}
// 			break;
// 		}
		cnt = mx/5;
		while(cnt--){
			for(char i= 1; i <14; i++){
				PORTC=0; PORTD = 0;PORTB=0xFF;
				PORTD=dump[i-1][0];PORTC=dump[i-1][1]; PORTB=i;
			}
			PORTB=0xFF;
		}
		for(char i = 0; i < 7; i++){
			dump[i][0]=alphabet[cur][i][0];
			dump[i][1]=alphabet[cur][i][1];
		}
		cur++;
		if(cur >5) cur=0;
	}


}