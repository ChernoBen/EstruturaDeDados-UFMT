/*
Implementação Arvore Multiplos filhos
*/

#ifndef ARVORE_MULT
#define ARVORE_MULT
#include <stdlib.h>
#include <stdio.h>

#define T 3
//estrutura da arvore
struct est_arv_mf{
    int valores[T];
    struct est_arv_mf *filhos[T+1];
    int contador;
};
typedef struct est_arv_mf tipo_arv_mf;

//prototipos
tipo_arv_mf *alocaNovoNoArvMf(int valor);
void insereArvMf(tipo_arv_mf **arv,int vl);
void percursoPreOrdemMf(tipo_arv_mf *arv);
void percursoPosOrdemMf(tipo_arv_mf *arv);
int buscaValorMf(tipo_arv_mf *arv,int vl);
int contaBilizaMf(tipo_arv_mf *arv);
void imprimeFolhasMf(tipo_arv_mf *arv);

//funcoes

//funcao que imprime folhas mf
void imprimeFolhasMf(tipo_arv_mf *arv){
    int i=0;
    if(arv==NULL){
        printf("");
    }else{
        if(arv->filhos != NULL){
            for(i=0;i<arv->contador-1;i++){
                imprimeFolhasMf(arv->filhos[i]);
            }
            
        }else{
            for(i=0;i<T;i++){
                printf("%d ",arv->valores[i]);
            }
        }
    }
}

//funcao que retorna total de itens na arv mf
int contaBilizaMf(tipo_arv_mf *arv){
    int total,i;
    total = 0;
    if(arv == NULL){
        return 0;
    }else{
        for(i=0;i<T;i++){
            total ++;
        }
        for(i=0;i<=arv->contador;i++){
            total += contaBilizaMf(arv->filhos[i]);
        }
        return total;
    }
}
//aloca novo no
tipo_arv_mf *alocaNovoNoArvMf(int valor){
    int i;
    tipo_arv_mf *novo_no;
    novo_no = (tipo_arv_mf*) malloc(sizeof(tipo_arv_mf));
    novo_no->valores[0] = valor;
    novo_no->contador=1;
    for(i=0;i<T+1;i++){
        novo_no->filhos[i] = NULL;
    }
    return novo_no;
}

//funcao que insere um novo valor na estrutura
void insereArvMf(tipo_arv_mf **arv,int vl){
    int i;
    if((*arv)==NULL){
        (*arv) = alocaNovoNoArvMf(vl);
    }else{
        //se a arvore menor que T, fazer inserção ordenada
        if((*arv)->contador<T){
            i = (*arv)->contador-1;
            while((i>=0)&&((*arv)->valores[i]>vl)){
                (*arv)->valores[i+1] = (*arv)->valores[i];
                i--;    
            }
            (*arv)->valores[i+1]=vl;
            (*arv)->contador++;
        }else{
            //se no cheio, identifique filho correto p/inserção
            i = 0;
            //Enquanto i menor que T e valores no nó maior que vl, caminhe p/ frente
            while(i<T && (*arv)->valores[i]<vl){
                i++;
            }
            //faça a chamada recursiva na posição do filho identificado
            insereArvMf(&(*arv)->filhos[i],vl);
        }
    }
}

//funcao que imprime em pre ordem arv MF
void percursoPreOrdemMf(tipo_arv_mf *arv){
    if(arv!=NULL){
        int i;
        for (i=0;i<arv->contador;i++){
            printf("%d ", arv->valores[i]);
        }
        //verifica se no e completo e chama recursivamente p/ os filhos
        if(arv->contador == T){
            for(i=0;i<T+1;i++){
                percursoPreOrdemMf(arv->filhos[i]);
            }
        }
    }
}

//funcao que imprime em pos ordem arv MF
void percursoPosOrdemMf(tipo_arv_mf *arv){
    if(arv!=NULL){
        int i;
        if(arv->contador == T){
            for(i=0;i<T+1;i++){
                percursoPreOrdemMf(arv->filhos[i]);
            }
        }
        for (i=0;i<arv->contador;i++){
            printf("%d ", arv->valores[i]);
        }
    }
}

//função que busca valor dentro da arvore mf
int buscaValorMf(tipo_arv_mf *arv,int vl){
    if(arv !=NULL){
        int i = 0;
        while(i<arv->contador && vl > arv->valores[i]){
            i++;
        }
        if(i<arv->contador && vl == arv->valores[i]){
            return vl;
        }else if(arv->filhos[i]!=NULL){
            return buscaValorMf(arv->filhos[i],vl);
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

//Em Order
void imprimirOrdemMf(tipo_arv_mf *arv){
    if(arv==NULL){
        return;
    }
    for(int i =0;i<arv->contador;i++){
        imprimirOrdemMf(arv->filhos[i]);
        printf("%d ",arv->valores[i]);
    }
    imprimirOrdemMf(arv->filhos[arv->contador]);
}

/*
Remoção	de	uma	chave	em	um	nó,	causando	
underflow	e	a	redistribuição	não	pode	ser	
aplicada
*/

#endif // !ARVORE_MULT