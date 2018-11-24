#include <string.h>
#include <stdio.h>

int main () {
   char str[200];
   const char s[2] = " ";
   char *token;
    
    while(1){
        //get the text
        puts("input the run command followed by the file:");
        fgets(str,sizeof(str),stdin);

        /* get the first token */
        token = strtok(str, s);
        
        /* walk through other tokens */
        while( token != NULL ) {
            printf( " %s\n", token );
            
            token = strtok(NULL, s);
        }
    }
    
   
   return(0);
}