#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <time.h>


//STRUCT DE PROCESSOS--------------------------------------------------------------------
using namespace std;

struct Processos{
  string nome;
  int pid;
  int v[10];
  
};

//FUNÇÕES PARA VERIFICAR PROCESSOS IGUAIS NA FILA DE PROCESSOS----------------------------
bool Existe (int valores[], int tam, int valor){
  for(int i = 0; i < tam; i++){
    if(valores[i]==valor){
      return true;
    }
  }
  return false;
}

void GerarAleatorios(int numeros[]){
  int v;
  for(int i = 0; i<10;i++){
    v = rand() % 10;
    while(Existe(numeros,i,v)){
      v = rand() % 10;
    }
  numeros[i] = v;
  }
}
//PROCESSOS--------------------------------------------------------------
void verProcessos(queue<Processos> pcs){
  int i;
cout << endl << "Fila Processos:" << endl;

    queue<Processos> aux1 = pcs;
    Processos aux2;

    while(!aux1.empty()){
      aux2 = aux1.front();
      cout << aux2.nome << ":" << '\t';
      for(i = 0; i < 10; i++){
        cout<< aux2.v[i] << '\t';
      }
      aux1.pop();
      cout << endl;
    }


  cout << endl;
}

//INSERÇÃO DOS VALORES DOS PROCESSOS NA REGIÃO CRITICA-----------------


void executarRC(queue <Processos>pcs, vector<int>rc){
  int qtde = 0;
  int i;

  for(int i = 0; i < 10; i++){
    Processos aux;
    aux = pcs.front();
    if(aux.v[0]!= -1){
        rc.insert(rc.begin(), aux.v, aux.v+10);
        qtde += 10;
    }
    else{
      if(rc.front()==0){

      }
      else{
        for(int j=0; j < 10; j++){
          rc.erase(rc.begin());
        }
        qtde -=10;
      }


    }
  pcs.pop();
  }

  cout << "Região Crítica:" << endl;

  for(i = 0; i < rc.size(); i++){
    if(rc[i] != 0){
    cout << "[" << rc[i] << "]";
    }
    else{
      
    }
  }

  cout << endl << "---------------------------------------------" << endl;
  
}


//MAIN --------------------------------------------------------------
int main(){
  srand (time(NULL));

  int i;
  int c[10];
  int qtde = 0;

  vector<int> rc(1000);

  queue<Processos> pcs;
  
//INSTANCIANDO OS PROCESSOS A PARTIR DA STRUCT-----------------------------------------
  Processos p1;
  Processos p2;
  Processos p3;
  Processos p4;
  Processos p5;
  Processos p6;
  Processos p7;
  Processos p8;
  Processos p9;
  Processos p10;

//ATRIBUIDO NOME E IDENTIFICAÇÃO AOS PROCESSOS-----------------------------------------
  p1.nome = "p1";
  p1.pid = 0;

  p2.nome = "p2";
  p2.pid = 1;

  p3.nome = "p3";
  p3.pid = 2;

  p4.nome = "p4";
  p4.pid = 3;

  p5.nome = "p5";
  p5.pid = 4;

  p6.nome = "p6";
  p6.pid = 5;

  p7.nome = "p7";
  p7.pid = 6;

  p8.nome = "p8";
  p8.pid = 7;

  p9.nome = "p9";
  p9.pid = 8;

  p10.nome = "p10";
  p10.pid = 9;

//ATRIBUIÇÃO DE VALORES RANDOMICOS EM CADA PROCESSO---------------------------------------


  for(i = 0; i < 10; i++){
    p1.v[i] = (rand() % 100)+1;
    p2.v[i] = (rand() % 100)+1;
    p3.v[i] = (rand() % 100)+1;
    p4.v[i] = (rand() % 100)+1;
    p5.v[i] = (rand() % 100)+1;
    p6.v[i] = -1;
    p7.v[i] = -1;
    p8.v[i] = -1;
    p9.v[i] = -1;
    p10.v[i] = -1;
    }

  GerarAleatorios(c);

//INSEÇÃO PROCESSOS ALEATÓRIOS NA FILA DE  PROCESSOS-------------------------------
  for(i = 0; i < 10; i++){

      if(c[i] == p1.pid){
        pcs.push(p1);
      }
      else if(c[i] == p2.pid){
        pcs.push(p2);
      }
      else if(c[i] == p3.pid){
        pcs.push(p3);
      }
      else if(c[i] == p4.pid){
        pcs.push(p4);
      }
      else if(c[i] == p5.pid){
        pcs.push(p5);
      }
      else if(c[i] == p6.pid){
        pcs.push(p6);
      }
      else if(c[i] == p7.pid){
        pcs.push(p7);
      }
      else if(c[i] == p8.pid){
        pcs.push(p8);
      }
      else if(c[i] == p9.pid){
        pcs.push(p9);
      }
      else if(c[i] == p10.pid){
        pcs.push(p10);
      }
      
  }


  verProcessos(pcs);
  executarRC(pcs, rc);
    
}