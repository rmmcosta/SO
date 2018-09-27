
// Name of program mainreturn.cpp 
#include <stdio.h>
#include <getopt.h> 

#define __LOGS__ 1
  
int main(int argc, char** argv) 
{ 

#ifdef __LOGS__
	printf("Begin\n");
#endif

	printf("You have entered %d arguments:\n", argc); 
	long opt;
	
    while ((opt = getopt(argc, argv, "b:x:y:z:")) != -1) {
		printf("opt:%ld\n", opt);
        switch (opt) {
            case 'b':
            case 'x':
            case 'y':
            case 'z':
                printf("%ld:%s\n",opt,optarg);
                break;
            case '?':
            case 'h':
            default:
                printf("default\n");
                break;
        }
    }
	
    return 0; 
} 