#include <stdio.h>
#include <math.h>

/*
Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.
*/
int main(void) {
  double a,b,c;
  double x1,x2;
  scanf("%lf %lf %lf",&a,&b,&c);
  x1 = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
  x2 = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
  if((x1 == -INFINITY) || (x2 == INFINITY)||(x1 == INFINITY)||(x2 == -INFINITY)){
    printf("Impossivel calcular\n");
  }else if(isnan(x1)||isnan(x2)){
    printf("Impossivel calcular\n");
  }else{
    printf("R1 = %.5lf\nR2 = %.5lf\n",x2,x1);
  }
  return 0;
}