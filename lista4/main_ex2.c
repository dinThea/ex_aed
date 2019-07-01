#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

int main () {

    char *palavra   = "ETSE OICICREXE E OTIUM LICAF";
    char *res       = (char*) malloc(sizeof(char)*(strlen(palavra)+1));
    Pilha *pilha    = criaPilha();
    int idx_res = 0;

    for (int i = 0; i <= strlen(palavra); i++){
        if (palavra[i] != ' ' && palavra[i] != '\0') {
            empilha (pilha, palavra[i]);
        } else {
            while (!pilhaVazia(pilha)) {
                res[idx_res++] = desempilha(pilha);
            }
            res[idx_res++] = ' ';
        }
    }
    res[idx_res] = '\0';

    printf ("%s\n", res);
    return 0;
}