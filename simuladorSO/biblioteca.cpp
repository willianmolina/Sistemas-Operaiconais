#include "util.h"

using namespace std;


void exibirProcessosUsuario(LISTA *l){
exibirProcessos(l);
}

int inserirProcessoUsuario(LISTA *l, PROCESSO elem){
return inserirProcesso(l, elem);
}

void systemCallUsuario(LISTA *l){
systemCall(l);
}

void finalizarProcessosUsuario(LISTA *l){
finalizarProcessos(l);
}

bool buscaPidDEPUsuario(LISTA *l, int pidBusca){
return buscaPidDEP(l, pidBusca);
}
