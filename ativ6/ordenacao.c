/*
Metodos de ordenação
*/
#ifndef ORDENACAO_C
#define ORDENACAO_C

#include <stdlib.h>
#include <stdlib.h>
#include "lista.c"



//prototipos
void bubbleSort(tipo_lista *lst);


//metodos
void bubbleSort(tipo_lista *lst){
    int flag_troca,aux,idx;
    flag_troca = 1;
    while(flag_troca ){
        //se em algum momento ocorrer troca, flag = 1
        flag_troca = 0;
        for (idx=0;idx<lst->contador-1;idx++){
            if (lst->lista[idx] > lst->lista[idx+1]){
                aux = lst->lista[idx];
                lst->lista[idx] = lst->lista[idx+1];
                lst->lista[idx+1]=aux;
                flag_troca = 1;
            }
        }

    }
}
#endif