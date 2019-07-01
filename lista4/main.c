#include <stdio.h>
#include "pilha.h"

int main() {

    Pilha *pilha = criaPilha();
    empilha(pilha, '0');
    empilha(pilha, '1');
    empilha(pilha, '2');
    printf ("%d\n", tamPilha(pilha));
    printf ("%d %c %c %c\n", tamPilha(pilha), desempilha(pilha), desempilha(pilha), desempilha(pilha));
    printf ("%d\n", tamPilha(pilha));

}