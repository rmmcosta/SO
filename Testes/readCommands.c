#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    const char EXIT_COMMAND[4] = "exit";
    const char RUN_COMMAND[3] = "run";
    char fileName[200];
    char str[200];
    const char s[2] = " ";
    char *token;
    
    while(1){
        //get the text
        puts("input the run command followed by the file:");
        fgets(str,sizeof(str),stdin);

        /* get the first token */
        token = strtok(str, s);
        if(strncmp(token,EXIT_COMMAND,4)==0)
            break;
        if(strncmp(token,RUN_COMMAND,3)==0){
            token = strtok(NULL, s);
            strcpy(fileName, token);
            printf("%s",fileName);
        } else {
            puts("Wrong command!");
        }
    }
    printf("Exited Simple Shell.\n");
    return 0;
}