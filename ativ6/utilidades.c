#ifndef UTILIDADES_C
#define UTILIDADES_C

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.c"

//prototipos
tipo_lista geraLista(int qtd);



//funcao que gera lista aleatoria
tipo_lista geraLista(int qtd){
    int i,val; 
    tipo_lista lista;
    inicializaLista(&lista);

    for (i=0;i<qtd+1;i++){
        //gera numeros inteiros de 0-9
        val = (rand()%10);
        insereFim(&lista,val);
    }
    return lista;
}

#endif