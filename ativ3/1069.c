#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *exp = (char *) malloc(sizeof(char) * 1000);
  int diamantes,entrada,counter = 0;
  scanf("%d",&entrada);
  while (scanf("%s", exp) != EOF) {

    int open = 0, i = 0;
      
    while (i < strlen(exp)) {

      if (exp[i] == '<') open++;
      if (exp[i++] == '>') {
        if (open > 0){
          open--;
          //printf("%d\n",open);
          diamantes ++;
        }
      }
    }
    printf("%d\n",diamantes);
    diamantes = 0;
    counter ++;
    if(entrada == counter){
      break;
    }
  }
  return 0;
}