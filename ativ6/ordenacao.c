/*
Metodos de ordenação
*/
#ifndef ORDENACAO_C
#define ORDENACAO_C

#include <stdlib.h>
#include <stdio.h>
#include "lista.c"



//prototipos
void bubbleSort(tipo_lista *lst);
void shellSort(tipo_lista *lst);
tipo_lista insertSort(tipo_lista lst);
void mergeSort(tipo_lista *lst);
void mergeSort_div(int vet[],int tam);
void merge(int vet[],int tam);
void quickSort(tipo_lista *lst);
void quickSort_interno(int vet[],int inicio,int fim);
void new_quick_sort(int *a, int left, int right);

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

void mergeSort_div(int vet[],int tam){
    int meio;
    if (tam > 1){
        // se tamanho maior que 1 dividir vetor e chamar mergeSort_div recursivamente
        meio = tam/2;
        mergeSort_div(vet,meio);
        mergeSort_div(&(vet[meio]),tam - meio);
        //juntar
        merge(vet,tam);
    }
}

void merge(int vet[],int tam){
    int *vet_aux;
    int meio,idx_aux,i,j;

    vet_aux = (int*) malloc(sizeof(int)*tam);
    meio = tam/2;
    i = 0;
    j = meio;
    idx_aux = 0;
    while((i < meio)&&(j < tam)){
        if (vet[i] < vet[j]){
            vet_aux[idx_aux++] = vet[i++];
        }else{
            vet_aux[idx_aux++] = vet[j++];
        }
    }

    while(i<meio){
        vet_aux[idx_aux++] = vet[i++];
    }

    while(j<tam){
        vet_aux[idx_aux++] = vet[j++];
    }
    //retornar valores ao vetor original
    for(i=0;i<tam;i++){
        vet[i] = vet_aux[i];
    }
    free(vet_aux);
}

void mergeSort(tipo_lista *lst){
    mergeSort_div(lst->lista,lst->contador);
}

void quickSort(tipo_lista *lst){
    new_quick_sort(lst->lista,0,lst->contador-1);
}

void quickSort_interno(int vet[],int inicio,int fim){
    int meio,pivo,i,j,aux,k;
    meio = ((fim-inicio)/2);
    pivo = vet[meio];
    i = inicio;
    j = fim;

    while(i <= j){
        while((vet[i]<pivo)&&(i<fim)){
            i++;
        }
        while((vet[j]>pivo)&&(j>inicio)){
            j--;
        }
        if (i <= j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    if(i==j){
        i++;
        j--;
    }
    if(j>inicio){
       quickSort_interno(vet,inicio,j); 
    }
    if(i<fim){
        quickSort_interno(vet,i,fim);
    }
}

void new_quick_sort(int *vet, int inicio, int fim) {
    int i, j, pivo, aux;
     
    i = inicio;
    j = fim;
    pivo = vet[(inicio + fim) / 2];
     
    while(i <= j) {
        while(vet[i] < pivo && i < fim) {
            i++;
        }
        while(vet[j] > pivo && j > inicio) {
            j--;
        }
        if(i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
     
    if(j > inicio) {
        new_quick_sort(vet, inicio, j);
    }
    if(i < fim) {
        new_quick_sort(vet, i, fim);
    }
}
#endif