#include <stdio.h>
/*
Escreva um programa que leia um valor inteiro N. Este N é a quantidade de linhas de saída que serão apresentadas na execução do programa.
*/
int main(void) {
  int n, linha;
  int primeiro,segundo,terceiro;
  scanf("%d",&n);
  int i;
  primeiro = i+1;
  segundo = i+2;
  terceiro = i+3;
  for(i=0;i<=n-1;i++){
    printf("%d %d %d PUM\n",primeiro,segundo,terceiro);
    primeiro = terceiro + 2;
    segundo = terceiro + 3;
    terceiro = terceiro + 4;
  }
  return 0;
}