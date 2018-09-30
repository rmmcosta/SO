#include <stdio.h>
#include <stdlib.h>

int main(){
	int thread;
	thread = fork();
	if(thread==0){
		printf("\nInside the child process.\n");
		exit(-1);
	}
	else{
		printf("\nInside the main process.\n");
	}
	return 0;
}
