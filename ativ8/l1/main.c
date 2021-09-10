#include <stdio.h>
#include <stdlib.h>

#include "arvore_binaria.c"
#include "arvore_mult.c"

int main(){
    /*
    Lista 1
    */
    //1#
    printf("QUESTAO 1#\n");
    tipo_arv_bin *arvore;
    arvore = NULL;
    //2#
    printf("QUESTAO 2#\n");
    insereArvBin(&arvore,10);
    insereArvBin(&arvore,3);
    insereArvBin(&arvore,9);
    insereArvBin(&arvore,13);
    insereArvBin(&arvore,18);
    insereArvBin(&arvore,20);
    insereArvBin(&arvore,40);
    insereArvBin(&arvore,9);
    insereArvBin(&arvore,14);
    //3#
    printf("QUESTAO 3#\n");
    int res = buscaValor(arvore,11);
    if(res == (-1)){
        printf("Valor nao encontrado\n");   
    }else{
        printf("Resultado: %d\n",res);    
    }
    //4#
    printf("QUESTAO 4#\n");
    arvore = removeValor(arvore,9);
    //5#
    printf("QUESTAO 5#\n");
    printf("total: %d\n",contaBilizaBin(arvore));
    //6#
    printf("QUESTAO 6#\n");
    printf("Altura: %d\n",obterAlturaArv(arvore));
    //7#
    printf("QUESTAO 7#\n");
    imprimeFolhas(arvore);
    printf("\n\n");
    //8#
    printf("QUESTAO 8#\n");
    imprimirNiveis(arvore);
    printf("\n\n");
    //9#
    printf("QUESTAO 9#\n");
    percursoPreOrdem(arvore);
    printf("\n");
    //10#
    printf("QUESTAO 10#\n");
    percursoPosOrdem(arvore);
    printf("\n");
    //11#
    printf("QUESTAO 11#\n");
    percursoOrdem(arvore);
    printf("\n");
    /*
    Lista 2
    */
    //1#
    tipo_arv_mf *arv;
    arv = NULL;
    //2#
    insereArvMf(&arv,10);
    insereArvMf(&arv,7);
    insereArvMf(&arv,1);

    insereArvMf(&arv,15);
    insereArvMf(&arv,0);
    insereArvMf(&arv,5);
    insereArvMf(&arv,8);
    //3#
    res = buscaValorMf(arv,9);
    if(res == (-1)){
        printf("Valor não encontrado ou arvore é nula\n");
    }else{
        printf("Valor %d encontrado!\n",res);
    }
    //9#
    percursoPreOrdemMf(arv);
    printf("\n");
    //10#
    percursoPosOrdemMf(arv);
    printf("\n");
    //insereArvMf(&arv,1);
    //printf("%d | %d | %d | %d \n",arv->valores[0],arv->valores[1],arv->valores[2],arv->valores[3]);
    return 1;
}