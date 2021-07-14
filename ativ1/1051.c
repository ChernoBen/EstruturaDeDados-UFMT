
#include <stdio.h>

/*
Leia um valor com duas casas decimais, equivalente ao salário de uma pessoa de Lisarb. Em seguida, calcule e mostre o valor que esta pessoa deve pagar de Imposto de Renda, segundo a tabela abaixo.
*/
typedef struct{
	int primeiro;
	int segundo;
	int terceiro;
	int quarto;
}Aliquota;

int main(void){
	Aliquota Nivel;
  	float salario;
  	float imposto;
  	float novoSalario;
  	float faixa,faixa2,faixa3;
  	scanf("%f",&salario);
	Nivel.primeiro = 0;
	Nivel.segundo = 8;
	Nivel.terceiro = 18;
	Nivel.quarto = 28;
  	if(salario<=2000){
    	printf("Isento\n");
  	}else if((salario>=2000.01)&&(salario<=3000.00)){
    	faixa = salario - 2000;
    	imposto = (faixa*Nivel.segundo)/100;
    	printf("R$ %.2f\n",imposto);
  	}else if((salario>=3000.01)&&(salario<=4500.00)){
    	faixa = (1000*Nivel.segundo)/100;
    	faixa2 = ((salario-3000)*Nivel.terceiro)/100;
    	imposto = faixa+faixa2;
    	printf("R$ %.2f\n",imposto);  
  	}else if(salario>4500.01){
    	faixa = (1000*Nivel.segundo)/100;
    	faixa2 = (1500*Nivel.terceiro)/100;
    	faixa3 = ((salario-4500)*Nivel.quarto)/100;
    	imposto = faixa+faixa2+faixa3;
    	printf("R$ %.2f\n",imposto);
  	}
	return 0;
}