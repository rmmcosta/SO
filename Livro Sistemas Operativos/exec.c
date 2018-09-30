#include <stdio.h>

int main(int argc, char *argv[]){
  int thread;
  thread = fork();
  if(thread==0){
    char* arr[] = {"ls", "-l", "-R", "-a", NULL};
    execv(argv[1],arr);
    printf("\nshould never print this!");
    exit(-1);
  }
  else{
    printf("\nInside the main process!\n");
  }
  return 0;
}
