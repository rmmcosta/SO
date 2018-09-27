#include <stdio.h>

int main(int argc, char**argv[]){
	printf("Other tread\n");
	printf("%d arguments.\n",argc);
	for(int i = 0; i<argc; i++){
		char* argpointer = argv[i];
		printf("Value %d: %s", *argpointer);
	}
}