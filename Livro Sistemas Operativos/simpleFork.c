#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

int main(){
	fork();
	printf("\nHello Fork!\n");
	return 0;
}
