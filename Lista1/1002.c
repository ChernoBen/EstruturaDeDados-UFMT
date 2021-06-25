#include <stdio.h>
#include <math.h>

/*
  A fórmula para calcular a área de uma circunferência é: area = π . raio2. Considerando para este problema que π = 3.14159:
  Efetue o cálculo da área, elevando o valor de raio ao quadrado e multiplicando por π.
*/
int main(void) {
  double raio;
  double pi = 3.14159;
  scanf ("%lf", &raio);
  double area = pi * pow(raio,2);
  printf("A=%.4f\n",area);
  return 0;
}