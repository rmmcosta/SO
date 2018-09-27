#include <stdio.h>
#include <stdlib.h>

int main(){
	int thread;
	thread = fork();
	if(thread==0){
		printf("Inside the child process.");
		exit(-1);
	}
	else{
		printf("Inside the main process.");
	}
	return 0;
}