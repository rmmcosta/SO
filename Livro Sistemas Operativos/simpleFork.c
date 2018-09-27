#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

int main(){
	fork();
	printf("Hello Fork!");
	return 0;
}