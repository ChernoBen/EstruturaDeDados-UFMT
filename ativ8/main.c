#include <stdio.h>
#include <stdlib.h>

#include "arvore_binaria.c"

int main(){
    //1#
    tipo_arv_bin *arvore;
    arvore = NULL;
    //2#
    insereArvBin(&arvore,10);
    insereArvBin(&arvore,3);
    insereArvBin(&arvore,9);
    insereArvBin(&arvore,13);
    insereArvBin(&arvore,18);
    insereArvBin(&arvore,20);
    insereArvBin(&arvore,40);
    //5#
    printf("total: %d\n",contaBilizaBin(arvore));
   //6#
    printf("Altura: %d\n",obterAlturaArv(arvore));
    //9#
    percursoPreOrdem(arvore);
    printf("\n");
    //10#
    percursoPosOrdem(arvore);
    printf("\n");
    //11#
    percursoOrdem(arvore);
    printf("\n");
    return 1;
}