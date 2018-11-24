#include <stdio.h>
#include <stdlib.h>

int main(){
    int pid,estado;
    pid=fork();
    if(pid==0){
        int err;
        char *args[]={"./programaFilho","inputs/ficheiro",NULL}; 
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