#include <stdio.h>

int main(int argc, char*argv[]){
	printf("Other tread\n");
	printf("%d arguments.\n",argc);
	int i = 0;
	for(i; i<argc; i++){
	  printf("Value %d: %s", argv[i]);
	}
}
