#include "gameover.cpp"

int birdHeight = 3;
int birdCol = 12;
bool up;



bool isHit(int r, int c){

	if(getBit(r,c-2)) return true;
	if(getBit(r+1,c-2)) return true;
	if(r>12) return true;
	return false;
}


void drawBird(int r=birdHeight, int c=birdCol){
	if(isHit(r,c)){
		gameover=true;
		return;
	}
	set(r,c);
	set(r,c+1);
	set(r+1,c-1);
	set(r+1,c);
	set(r+1,c+2);

	set(r+2,c);
	set(r+2,c+1);
	set(r+2,c+2);
}

void eraseBird(int r=birdHeight,int c=birdCol){
	if(up){
		r++;
	}
	else{
		r--;
	}
	reset(r,c);
	reset(r,c+1);
	reset(r+1,c-1);
	reset(r+1,c);
	reset(r+1,c+2);
	reset(r+2,c);
	reset(r+2,c+1);
	reset(r+2,c+2);
}

