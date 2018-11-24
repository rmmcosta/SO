#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void launchSolver(char *fileName);

int main(int argc, char** argv){
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
        launchSolver(fileName);
    } else {
        puts("Wrong command!");
    }
  }
  printf("Exited Simple Shell.\n");
  return 0;
}

void launchSolver(char *fileName){
  int pid,estado;
  pid=fork();
  if(pid==0){
    int err;
    char *args[]={"./CircuitRouter-SeqSolver",fileName,NULL}; 
    err = execvp(args[0],args); 
    printf("Algo correu mal. execv com erro %d\n", err);
    exit(-1);
  } else {
    int returnWait;
    printf("processo pai a correr o processo filho %d\n",pid);
    returnWait = wait(&estado);
    printf("O processo %d terminou com o estado %d\n",returnWait,estado);
  }
}