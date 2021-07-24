#include <stdio.h>
#include <stdlib.h>
#define N 10

struct est_fila{
  int fila[N];
  int contador;
};
typedef struct est_fila tipo_fila;

void inicializaFila(tipo_fila *fl);
void insereFila(tipo_fila *fl,int valor);
int removeFila(tipo_fila *fl);
//não executará modificação entao nao precisa de ponteiro
void imprimeFila(tipo_fila fl);

//---------------------------
int main(){
  tipo_fila fila;
  fila.contador = 0;

  int entrada,status;
  status = 1;
  tipo_fila exatas,humanas,saude;
  
  exatas.contador= 0 ;
  humanas.contador = 0;
  saude.contador = 0;

  inicializaFila(&exatas);
  inicializaFila(&humanas);
  inicializaFila(&saude);

  int lvl1,lvl2,lvl3,lvl4;
  int eCounter,hCounter,sCounter,eAlunos,hAlunos,sAlunos;

  eCounter = 0;
  hCounter = 0;
  sCounter = 0;
  eAlunos = 0;
  sAlunos = 0;
  hAlunos = 0;

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
          if(eCounter > 0){
            printf("Entre com a quantidade em inteiro de alunos que gostaria de atender\n");
            scanf("%d",&eAlunos);
            if(eAlunos<eCounter){
              printf("Senhas exatas atendidas com sucesso:[");
              for (int i=0; i<eAlunos;i++){
                printf(" %d ",removeFila(&exatas));
                eCounter--;
              }
              printf("]\n");
            }else{
              printf("Quanidade de atendimentos supera quantidade em fila\n");
            }
          }else{
            printf("Fila de exatas atualmente vazia!\n");
          }

        }else if(lvl1 == 2){
          if(hCounter > 0){
            printf("Entre com a quantidade em inteiro de alunos que gostaria de atender\n");
            scanf("%d",&hAlunos);
            if(hAlunos<hCounter){
              printf("Senhas humanas atendidas com sucesso:[");
              for(int i=0;i<hCounter;i++){
                printf(" %d ", removeFila(&humanas));
                hCounter--;
              }
              printf("]\n");

            }else{
              printf("Quanidade de atendimentos supera quantidade em fila\n");
            }
          }else{
            printf("Fila de humanas atualmente vazia!\n");
          }

        }else if(lvl1 == 3){
          if(sCounter > 0){
            printf("Entre com a quantidade em inteiro de alunos que gostaria de atender\n");
            scanf("%d",&sAlunos);
            if(sAlunos<sCounter){
              printf("Senha %d saúde atendido com sucesso\nAguardando atendimento: %d\n \n",removeFila(&saude),sCounter--);
              for(int i= 0; i<0;i++){
                printf(" %d ",removeFila(&saude));
                sCounter--;
              }
              printf("]\n");
            }else{
              printf("Quanidade de atendimentos supera quantidade em fila\n");
            }
          }else{
            printf("Fila da Saúde atualmente vazia!\n");
          }
          
        }else{
          printf("Voltando para menu principal\n \n \n");
          lvl4 = 1;
        }
      }
// -------------------entrada de alunos ---------------------      
    }else if(entrada == 2){
      lvl3 = 0;
      while(lvl3 !=1){
        printf("Para cadastrar um novo aluno primeiro informe o tipo de curso\nPara exatas entre com: 4\nPara humanas entre com :5\nPara saúde entre com: 6\nEntre com 0 para voltar ao inicio\n");
        scanf("%d",&lvl2);
        if (lvl2 == 4){
          eCounter++;
          insereFila(&exatas,eCounter);
          printf("Senha fila exatas: %d\n \n \n",eCounter);
        }else if(lvl2 == 5){
          hCounter++;
          insereFila(&humanas,hCounter);
          printf("Senha fila humanas: %d\n \n \n",hCounter);
        }else if(lvl2 == 6){
          sCounter++;
          insereFila(&saude,sCounter);
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

// no aloc
int removeFila(tipo_fila *fl){
  if(fl->contador > 0){
    int aux;
    aux = fl->fila[0];
    //atualiza as posições no vetor
    for(int i=0;i<fl->contador-1;i++){
      fl->fila[i] = fl->fila[i+1];
    }
    fl->contador--;
    return aux;
  }else{
    printf("[error] fila vazia");
    return -1;
  }
}

void imprimeFila(tipo_fila fl){
  int i;
  printf("[");
  for (i=0;i<fl.contador;i++){
    printf("%d ",fl.fila[i]);
  }
  printf("]\n");
}

void inicializaFila(tipo_fila *fl){
  fl->contador = 0;
}

void insereFila(tipo_fila *fl, int valor){
  if (fl->contador < N){
    fl->fila[fl->contador] = valor;
    fl->contador++;
  }else{
    printf("---[Error] fila estáá cheia---");
  }
}
