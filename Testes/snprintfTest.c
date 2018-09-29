#include <stdio.h>
#include <stdlib.h>

void messageWithNum(int num, char **message) {
	int messageSize = 50;
	*message = malloc(messageSize);
	snprintf(*message,messageSize,"The message with %d", num);
}

int main(){
	char *message;
	messageWithNum(5,&message);
	printf("%s",message);
	return 0;
}