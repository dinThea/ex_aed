#include <stdio.h>
#include "arvore.h"

int main() {

    Arvore arvore = criaArvore(0);
    popular(arvore, 4, 1);
    imprimeERD(arvore); // Questao 2
    printf ("\n");
    imprimeIterativoPilha (arvore, 0); // ERD
    printf ("\n");
    imprimeIterativoPilha (arvore, 1); // RED
    printf ("\n");
    // imprimeIterativoPilha (arvore, 2); // EDR (pra depois)
    printf ("\n Altura: %d\n", altura(arvore));

    return 0;
}