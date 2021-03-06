#include <stdio.h>

/*
"#include <stdio.h>" :
permite que qualquer tipo de entrada ou saida
seja processada pela linguagem
*/

int main(void) {
  int integer;
  float floatNumber;
  
  integer = 10;
  floatNumber = 5.7;
  /*
    %d integer
    %c char
    %f float
  */
  //conditionals
  if(integer>floatNumber){
    printf("int is bigger than float\n");
  }else{
    printf("float is bigger than int\n");
  }

  //cases
  switch(integer){
    case 1:
      printf("Value is 1\n");
      break;
    case 2:
      printf("Value is 2\n");
      break;
    case 10:
      printf("Value is 10\n");
      break;
    default:
      printf("Unexpected value\n");
  }

  //iterators
  while(integer>floatNumber){
    printf("... %f\n",floatNumber);
    floatNumber ++;
  }

  do{
    printf("... %d\n",integer--);
  }while(integer != 0);

  for (count=0;count<=5;count++){
    printf("....counter:%d",count);
  }

  printf("Hello World\n");
  return 0;
}