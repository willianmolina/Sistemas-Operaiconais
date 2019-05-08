#include "util.h"

using namespace std;
LISTA listaProcessos;
int contadorProcessos = 0;


int main()
{
inicializar(&listaProcessos);
PROCESSO novo;
int op, auxNum, i;
char auxChar;

for(i=1; i<21; i++){
novo.PID = i;
novo.nome = "p";
novo.prioridade = i;
novo.tempoTotal = i;
novo.tempoParcial = i;
        novo.dependencia = false;
        novo.estado = PRONTO;
        novo.pidDEP = -1;
inserirProcessoUsuario(&listaProcessos, novo);
}


menu:
cout << "1 - Inserir Processo \t 2 - Lista Processos \t 3 - Executar Processos \t 4 - Limpar processos \t 5 - Sair" << endl;
cin >> op;

if(op == 1){
    cout << "PID: ";
    cin >> novo.PID;
    cout << "Nome: ";
    cin >> novo.nome;
    cout << "Prioridade: ";
    cin >> novo.prioridade;
    cout << "Tempo de Processamento: ";
    cin >> novo.tempoTotal;
    novo.tempoParcial = novo.tempoTotal;
    cout << "Possui dependencia? S/N" << endl;
    cin >> auxChar;
    if(auxChar == 'S' || auxChar == 's'){
    novo.dependencia = true;
    novo.estado = BLOQUEADO;
    cout << "PID do processo que este é dependente: ";
    cin >> novo.pidDEP;
    }
    else if (auxChar == 'N' || auxChar == 'n'){
        novo.dependencia = false;
        novo.estado = PRONTO;
        novo.pidDEP = -1;
    }
    else{
        cout << "Entrada inválida - Processo não adicionado" << endl;
        goto menu;
    }
    if(contadorProcessos < 2048){
  auxNum = inserirProcessoUsuario(&listaProcessos, novo);

    if(auxNum == 1){
      contadorProcessos ++;
      cout << "Processo adicionado!!" << endl;
      sleep(1);
      system("clear");
    }
    }
    else{
  cout << "Limite de memória atingido, favor limpar os processos para adicionar um novo!" << endl;
    }

    auxChar = '\0';
    novo.dependencia = false;
    goto menu;
}
else if(op==2){
    system("clear");
    cout << "LISTA DE PROCESSOS" << endl;
    exibirProcessosUsuario(&listaProcessos);
    goto menu;
}
else if (op==3){
    system("clear");
    systemCallUsuario(&listaProcessos);
    goto menu;
}
else if(op==4){
    cout << "Finalizando todos os processos" << endl;
    sleep(2);
    finalizarProcessosUsuario(&listaProcessos);
    goto menu;
}
else if (op == 5){
    cout << "Finalizando todos os processos" << endl;
    sleep(2);
    finalizarProcessosUsuario(&listaProcessos);
    contadorProcessos = 0;
    return 0;
}
else{
    cout << "Opção errada, tente novamente" << endl;
    contadorProcessos = 0;
    goto menu;
}



}
