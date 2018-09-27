
// Name of program mainreturn.cpp 
#include <stdio.h> 
  
int main(int argc, char** argv) 
{ 
    printf("You have entered %d arguments:\n", argc); 
	char line[256];
    gets(line);
	printf("line:%s", line);
  
    return 0; 
} 