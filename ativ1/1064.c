#include <stdio.h>

/*
Leia 6 valores. Em seguida, mostre quantos destes valores digitados foram positivos. Na próxima linha, deve-se mostrar a média de todos os valores positivos digitados, com um dígito após o ponto decimal.
*/

int main(void){
  double a,b,c,d,e,f;
  scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
  double media;
  int counter;
  if(a > 0){
    counter ++;
    media += a;
  }
  if(b > 0){
    counter ++;
    media += b;
  }
  if(c > 0){
    counter ++;
    media += c;
  }
  if(d > 0){
    counter ++;
    media += d;
  }
  if(e > 0){
    counter ++;
    media += e;
  }
  if(f > 0){
    counter ++;
    media += f;
  }
  printf("%d valores positivos\n",counter);
  printf("%.1lf\n",(media/counter));
	return 0;
}