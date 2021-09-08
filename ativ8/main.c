#include <stdio.h>
#include <stdlib.h>

#include "arvore_binaria.c"

int main(){
    tipo_arv_bin *arvore;
    arvore = NULL;
    insereArvBin(&arvore,10);
    insereArvBin(&arvore,3);
    insereArvBin(&arvore,9);
    insereArvBin(&arvore,13);
    insereArvBin(&arvore,18);
    insereArvBin(&arvore,20);
    insereArvBin(&arvore,40);
    //impressão em pré ordem
    percursoPreOrdem(arvore);
    printf("\n");
    percursoPosOrdem(arvore);
    printf("\n");
    percursoOrdem(arvore);
    printf("\n");
    return 1;
}