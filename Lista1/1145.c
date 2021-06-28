#include <stdio.h>
/*
Escreva um programa que leia dois valores X e Y. A seguir, mostre uma sequência de 1 até Y, passando para a próxima linha a cada X números.
*/
int main(void) {
  int X,Y,initial,counter;
  scanf("%d %d",&X,&Y);
  int i;
  initial = X;
  counter = 1;
  for(i=0;i<=Y-1;i++){
    if(counter>initial-1){
      printf("%d\n",i+1);
      counter=1;
    }else{
      printf("%d ",i+1);
      counter +=1;
    }
  }
  return 0;
}