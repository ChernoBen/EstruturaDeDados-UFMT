#include <stdio.h>
/*
Leia o salário do funcionário e calcule e mostre o novo salário, bem como o valor de reajuste ganho e o índice reajustado, em percentual.
*/
typedef struct{
	int primeiro;
	int segundo;
	int terceiro;
	int quarto;
	int quinto;
}Aumento;

int main(void){
	Aumento Nivel;
  float salario;
  float reajuste;
  float novoSalario;
  scanf("%f",&salario);
	Nivel.primeiro = 15;
	Nivel.segundo = 12;
	Nivel.terceiro = 10;
	Nivel.quarto = 7;
	Nivel.quinto = 4;
  if(salario<=400){
    novoSalario = salario+((salario*Nivel.primeiro)/100);
    reajuste = (salario*Nivel.primeiro)/100;
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.d %%\n",novoSalario,reajuste,Nivel.primeiro);
  }else if((salario>400)&&(salario<=800)){
    novoSalario = salario+((salario*Nivel.segundo)/100);
    reajuste = (salario*Nivel.segundo)/100;
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.d %%\n",novoSalario,reajuste,Nivel.segundo);
  }else if((salario>800)&&(salario<=1200)){
    novoSalario = salario+((salario*Nivel.terceiro)/100);
    reajuste = (salario*Nivel.terceiro)/100;
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.d %%\n",novoSalario,reajuste,Nivel.terceiro);
  }else if((salario>1200)&&(salario<=2000)){
    novoSalario = salario+((salario*Nivel.quarto)/100);
    reajuste = (salario*Nivel.quarto)/100;
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.d %%\n",novoSalario,reajuste,Nivel.quarto);
  }else if(salario>2000){
    novoSalario = salario+((salario*Nivel.quinto)/100);
    reajuste = (salario*Nivel.quinto)/100;
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.d %%\n",novoSalario,reajuste,Nivel.quinto);
  }
	return 0;
}