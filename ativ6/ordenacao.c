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
void shellSort(tipo_lista *lst);
tipo_lista insertSort(tipo_lista lst);



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

void shellSort(tipo_lista *lst){
    int flag_troca,aux,idx,k;
    k = lst->contador/2;
    flag_troca = 1;
    while(k > 1){
        idx = 0;
        while(idx+k< lst->contador){
            if (lst->lista[idx] > lst->lista[idx+k]){
                aux = lst->lista[idx];
                lst->lista[idx] = lst->lista[idx+k];
                lst->lista[idx+k]=aux;
            }
            idx++;
        }
        k--;
    }
    while(flag_troca){
        flag_troca=0;
        idx=0;
        while(idx<lst->contador-1){
            if (lst->lista[idx] > lst->lista[idx+1]){
                aux = lst->lista[idx];
                lst->lista[idx] = lst->lista[idx+1];
                lst->lista[idx+1]=aux;
                flag_troca=1;
            }
            idx++;
        }
    }
}

tipo_lista insertSort(tipo_lista lst){
    int idx_lst,idx;
    tipo_lista lst_ordenada;
    inicializaLista(&lst_ordenada);
    for(idx_lst=0;idx_lst<lst.contador;idx_lst++){
        //para cada elemento uma inserção ordenada
        if(lst_ordenada.contador == 0){
            insereFim(&lst_ordenada,lst.lista[idx_lst]);
        }else{
            idx = lst_ordenada.contador-1;
            while((idx >= 0) && (lst.lista[idx_lst]<lst_ordenada.lista[idx])){
                idx--;
            }
            inserePosicao(&lst_ordenada,lst.lista[idx_lst],idx+1);
        }
    }
    return lst_ordenada;
}

#endif