#include <stdio.h>
#include "pilha.h"

int main () {

    Pilha *pilha = criaPilha();    
    
    while(!pilhaVazia(pilha) && consultaTopo(pilha) == 'A') desempilha(pilha);
    empilha(pilha, 'B');

}