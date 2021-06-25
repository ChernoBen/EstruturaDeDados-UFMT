#include <stdio.h>
/*
Com base na tabela abaixo, escreva um programa que leia o código de um item e a quantidade deste item. A seguir, calcule e mostre o valor da conta a pagar.
*/
typedef struct{
	float cachorroQuente;
	float x_salada;
	float  x_bacon;
	float torradaSimples;
	float refigerante;
}Cardapio;

int main(void){
	Cardapio Card;
  	int codigo,quantidade;
  	scanf("%d %d",&codigo,&quantidade);
	Card.cachorroQuente = 4.00;
	Card.x_salada = 4.50;
	Card.x_bacon = 5.00;
	Card.torradaSimples = 2.00;
	Card.refigerante = 1.50;
  	switch(codigo){
    	case 1:
      		printf("Total: R$ %.2f\n",(quantidade*Card.cachorroQuente));
      		break;
    	case 2:
      		printf("Total: R$ %.2f\n",(quantidade*Card.x_salada));
      		break;
    	case 3:
      		printf("Total: R$ %.2f\n",(quantidade*Card.x_bacon));
      		break;
		case 4:
      		printf("Total: R$ %.2f\n",(quantidade*Card.torradaSimples));
      		break;
    	case 5:
      		printf("Total: R$ %.2f\n",(quantidade*Card.refigerante));
      	break;
  	}
	return 0;
}