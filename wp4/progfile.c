/* ==================================== 
File name: exerc_4_4.c
Date: 2015/02/19 
Group Number: 19
Members that contributed: 
Mahsa abbasian
Mohammad ali
Sally masry
Demonstration code:to be set
====================================== */ 
#include <stdio.h>
#include <stdlib.h>

#define REG8(x) *((unsigned char *)(x))
#define PORTA 0x09C0 // IN-port

int read(){
	return REG8(PORTA);
}
void write(int input){
	printf("%d  ---  %x\n",input,input);	
}
int check(int input, int new){
	if(new > 15 || new < 0)
		return 0;
	if(input == new)
		
		return 0;
	else
		return 1;
}
void main(){
	int i =0;
	int old;
	int new;
	puts("HELLO");
	while(1){
		new = read();
		if(check(old,new)){
			write(new);
			old = new;
		}
		for(i=0;i<100;i++){
			i = i + 1 -1;
		}
	}
	return 0;

}
