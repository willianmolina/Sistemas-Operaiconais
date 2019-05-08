#include "util.h"

using namespace std;

void inicializar(LISTA *l){
    l->inicio=NULL;
}

void exibirProcessos(LISTA *l){

PONT aux = l->inicio;
cout << "-------------------------------------------------------------------------------------------------------" << endl;
while(aux!=NULL){
cout << "PID: [" << aux->proce.PID << "] Nome: [" << aux->proce.nome << "] Estado: [";
switch(aux->proce.estado){
case PRONTO:
    cout << "PRONTO";
    break;
case BLOQUEADO:
    cout << "BLOQUEADO";
    break;
case EXECUTANDO:
    cout << "EXECUTANDO";
    break;
case FINALIZADO:
    cout << "FINALIZADO";
    break;
default:
    cout << "PRONTO";
    break;
}
cout << "] Prioridade: [" << aux->proce.prioridade;
printf("] Porcentagem: [%.2f]\n", aux->proce.porcentagem);
cout << "-------------------------------------------------------------------------------------------------------" << endl;

aux = aux->prox;
}
}

int inserirProcesso(LISTA *l, PROCESSO elem){
if(elem.PID <=0){
    cout << "PID inválido - Processo não inserido" << endl;
    return -1;
}
if(elem.tempoTotal <=0){
    cout << "Tempo de processamento inválido - Processo não inserido" << endl;
    return -1;
}


PONT ant = NULL;
PONT atual = NULL;
PONT novo = NULL;

novo = (PONT) malloc(sizeof(ELEMENTO));


if(novo==NULL){
cout << "Erro ao alocar memória - Processo não inserido" << endl;
return -1;
}

novo->proce=elem;
novo->prox=NULL;

atual = l->inicio;

while(atual!=NULL && elem.prioridade<atual->proce.prioridade){
ant=atual;
atual=atual->prox;

}
novo->prox=atual;


if(ant==NULL){
l->inicio=novo;
}

else{
ant->prox=novo;
}
return 1;

}


void busca(LISTA *l, int pidBusca){
PONT atual = NULL;

atual = l->inicio;

while(atual!=NULL && atual->proce.pidDEP!=pidBusca){
atual = atual->prox;
}
if(atual!= NULL && atual->proce.pidDEP==pidBusca){
  if(atual->proce.estado == FINALIZADO){
  atual->proce.estado = FINALIZADO;
  }
  else{
  atual->proce.estado = PRONTO;
}
}

}


void systemCall(LISTA *l){
PONT atual = l->inicio;
int tempoProcessamento = 0;

while(atual!=NULL){
    if(atual->proce.estado == PRONTO || atual->proce.estado == BLOQUEADO){
        tempoProcessamento += atual->proce.tempoTotal;
    }
    atual= atual->prox;
}


recall:
atual = l->inicio;
exibirProcessos(l);
while (atual!= NULL && tempoProcessamento > 0 ){
    if(atual->proce.estado == PRONTO && atual->proce.tempoParcial > 0){

if(atual->proce.tempoTotal>=5){
        if(atual->proce.tempoParcial<5){
          tempoProcessamento -= atual->proce.tempoParcial;
                atual->proce.tempoParcial = 0;
        }
        else{
          tempoProcessamento -=5;
          atual->proce.tempoParcial -= 5;
        }

}
else{
	tempoProcessamento -= atual->proce.tempoTotal;
        atual->proce.tempoParcial = 0;
}

        atual->proce.estado = EXECUTANDO;
        atual->proce.porcentagem = ((atual->proce.tempoTotal - atual->proce.tempoParcial)*100)/atual->proce.tempoTotal;

    if(atual->proce.porcentagem >= 100){
        atual->proce.porcentagem = 100;
        atual->proce.tempoParcial = 0;
        atual->proce.estado = FINALIZADO;
        busca(l, atual->proce.PID);
    }
    else if(atual->proce.porcentagem < 100 && atual->proce.estado!= FINALIZADO){
        atual->proce.estado = PRONTO;
    }
        system("clear");
        exibirProcessos(l);
        cout << "\nEXECUTANDO -> \t PID: [" << atual->proce.PID << "] Nome: [" << atual->proce.nome << "] Estado: [EXECUTANDO]";
        printf(" Porcentagem: [%.2f]\n\n", atual->proce.porcentagem);
        sleep(1);
        system("clear");

    }
        if(atual->proce.porcentagem >= 100){
	atual->proce.estado = FINALIZADO;
        busca(l, atual->proce.PID);
    }

    if(tempoProcessamento > 0 && atual->prox == NULL){
        goto recall;
    }
    else if(tempoProcessamento > 0){
        atual = atual->prox;
    }
}
finalizarProcessosFINALIZADOS(l);
}

void finalizarProcessos(LISTA *l){
PONT aux=l->inicio;


while(aux!=NULL){
l->inicio=l->inicio->prox;
free(aux);
aux=l->inicio;
}
}

void finalizarProcessosFINALIZADOS(LISTA *l){

  PONT atual = NULL;
  PONT ant = NULL;

teste:
  atual= l->inicio;

  while(atual!=NULL && atual->proce.estado !=FINALIZADO){
  ant = atual;
  atual=atual->prox;
  }

  if(atual != NULL && atual->proce.estado == FINALIZADO){

  if(ant==NULL){
  l->inicio=atual->prox;
  }
  else{
  ant->prox=atual->prox;
  }
  free(atual);
goto teste;
}


}
