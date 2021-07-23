#include <stdio.h>
#include <stdlib.h>

//estrutura do da fila
struct estru_no{
  int valor;//espaco para guardar valor
  struct estru_no *prox;//guarda endereco para outra estrutura
  struct estru_no *ant;
};
typedef struct estru_no tipo_no;
tipo_no *alocaNovoNo(int vl);
//prototipos
//inserções
void insereFim(tipo_no **ls,int vl);
//remocoes
int removeInicio(tipo_no **ls);
//impressoes
void imprimeLista(tipo_no *ls);

//---------------------------
int main(){
  int entrada,status;
  status = 1;
  tipo_no *exatas,*humanas,*saude;
  exatas = NULL;
  humanas = NULL;
  saude=NULL;
  int lvl1,lvl2,lvl3,lvl4;
  int eCounter,hCounter,sCounter;
  eCounter = 0;
  hCounter = 0;
  sCounter = 0;
  while(status == 1){
    printf("Selecione 1 para atendimento e 2 para demais serviços como gerar senha\nEntre com 0 para sair\n");
    printf("Status das filas:\nExatas em espera: %d\nHumanas em espera: %d\nSaúde em espera: %d\n",eCounter,hCounter,sCounter);
    scanf("%d", &entrada);
    if(entrada == 1 ){
      lvl4 = 0;
      while(lvl4 !=1){
        printf("Selecione qual área gostaria de atender\nEntre com 1 p/ exatas\nEntre com 2 p/ humanas\nEntre com 3 p/ saúde\nEntre com 0 p/ voltar ao inicio\n ");
        scanf("%d",&lvl1);
        if(lvl1 == 1){
          printf("Senha %d exatas atendido com sucesso\nAguardando atendimento: %d\n \n",removeInicio(&exatas),eCounter--);
        }else if(lvl1 == 2){
          printf("Senha %d humanas atendido com sucesso\nAguardando atendimento: %d\n \n",removeInicio(&humanas),hCounter--);
        }else if(lvl1 == 3){
          printf("Senha %d saúde atendido com sucesso\nAguardando atendimento: %d\n \n",removeInicio(&saude),sCounter--);
        }else{
          printf("Voltando para menu principal\n \n \n");
          lvl4 = 1;
        }
      }
    }else if(entrada == 2){
      lvl3 = 0;
      while(lvl3 !=1){
        printf("Para cadastrar um novo aluno primeiro informe o tipo de curso\nPara exatas entre com: 4\nPara humanas entre com :5\nPara saúde entre com: 6\nEntre com 0 para voltar ao inicio\n");
        scanf("%d",&lvl2);
        if (lvl2 == 4){
          eCounter++;
          insereFim(&exatas,eCounter);
          printf("Senha fila exatas: %d\n \n \n",eCounter);
        }else if(lvl2 == 5){
          hCounter++;
          insereFim(&humanas,hCounter);
          printf("Senha fila humanas: %d\n \n \n",hCounter);
        }else if(lvl2 == 6){
          sCounter++;
          insereFim(&saude,sCounter);
          printf("Senha fila saúde: %d\n \n \n",sCounter);
        }else{
          printf("Voltando para menu principal\n \n \n");
          lvl3 = 1;
        }
      }
    }else{
      break;
    }
  }
  return 1;
}


//------------------------

int removeInicio(tipo_no **ls){
  tipo_no *aux;
  int vl;
  if((*ls)->prox!=NULL){
    vl = (*ls)->prox->valor;
    aux = (*ls)->prox;
    (*ls)->prox = (*ls)->prox->prox;
    if((*ls)->prox !=NULL){
      (*ls)->ant = (*ls);
    }
    free(aux);
    return vl;
  }else{
    printf("[error]lista vazia");
    return -1;
  }
}

void insereFim(tipo_no **ls,int vl){
  tipo_no *aux,*novo_no;
  int count =0;
  if((*ls)==NULL){
    (*ls) = alocaNovoNo(vl);
  }else{
    aux = (*ls);
    while(aux->prox !=NULL){
      aux = aux->prox;
      count ++;
    }
    if(count==0){
      novo_no = alocaNovoNo(vl);
      novo_no->ant = aux;
      aux->prox = novo_no;
    }else{
      int val = aux->valor;
      novo_no = alocaNovoNo(aux->valor);
      aux->valor = vl;
      aux->prox = novo_no;
    } 
  }
}

//funcao de alocação
tipo_no *alocaNovoNo(int vl){
  //#1 criar um ponteiro tipo_no
  tipo_no *novo_no;
  //#2 alocar um espaco na memoria
  novo_no = (tipo_no*) malloc(sizeof(tipo_no));
  //#3 inicializar
  novo_no->valor = vl;
  novo_no->prox = NULL;
  novo_no->ant = NULL;
  //#4 retornar endereco de memoria do ponteiro criado
  return novo_no;
}