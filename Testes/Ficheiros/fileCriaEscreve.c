//
// Created by Ricardo on 09/10/2018.
//
#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp;
    char fileName[100];
    const char END_TYPING[1] = "q";
    puts("Input the file name:");
    gets(fileName);
    fp = fopen(fileName,"w");
    char fileLine[500];
    puts("Starting typing to the file. To end typing, type <q> ");
    while(1){
        gets(fileLine);
        if(strncmp(fileLine, END_TYPING, 1)==0)
            break;
        fprintf(fp,fileLine);
        fprintf(fp,"\n");
        fflush(fp);
    }
    fclose(fp);
}

