unsigned int graph[16]={0};

void set(int r, int c){
	graph[r] = (graph[r]|(1<<c));
}

void reset(int r, int c){
	graph[r]=(graph[r]&(~(1<<c)));
}

char getD(int i){
	char c = graph[i]>>8;
	return c;
}

char getC(int i){
	char c=graph[i]&255;
	return c;
}

void draw(){
	for(int i = 0; i <16; i++){
		PORTB=0xFF;
		PORTD=getD(i);
		PORTC=getC(i);
		PORTB=i;
	}
}