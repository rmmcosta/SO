#include <stdio.h>

int main(int argc, char *argv[]){
  printf("\ninside other thread 2\n");
  printf("\n%d arguments\n",argc);
  int i = 0;
  for(i;i<argc;i++){
    printf("\nvalue %d: %s\n",argv[i]);
  }
}
