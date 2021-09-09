#include <stdio.h>
#include <stdlib.h>

#include "arvore_binaria.c"

int main(){
    //1#
    printf("QUESTAO 1#");
    tipo_arv_bin *arvore;
    arvore = NULL;
    //2#
    printf("QUESTAO 2#");
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
    printf("QUESTAO 3#");
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
    return 1;
}