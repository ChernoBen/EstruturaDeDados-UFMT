#include <stdio.h>
/*
Calcule o consumo médio de um automóvel sendo fornecidos a distância total percorrida (em Km) e o total de combustível gasto (em litros).
*/
int main(void) {
  int x;
  double y;
  double z; 
  scanf("%d %lf",&x,&y);
  z = x/y;
  printf("%.3lf km/l\n",z);
  return 0;
}