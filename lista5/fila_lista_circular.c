#include "fila_lista.h"
#include <stdlib.h>

typedef struct celula_t {
    int conteudo[2];
    Celula *prox;
} Celula;

Celula *criaFila() {
    Celula *cabeca = (Celula*) malloc (sizeof(Celula));
    cabeca->conteudo[0] = 0;
    cabeca->conteudo[1] = 0;
    cabeca->prox = NULL;

    return cabeca;
};

void insereFila(Celula *c, int x, int y) {
    if (!filaCheia(c)) {
        Celula *nova = (Celula*) malloc (sizeof(Celula));
        nova->conteudo[0] = x;
        nova->conteudo[1] = y;
        if (filaVazia(c)) {
            c->prox = nova;  
            nova->prox = c; 
        } else {
            nova->prox = (c->prox)->prox;
            (c->prox)->prox = nova;              
        }
    } 
};

void removeFila(Celula *c, int *x, int *y) {
    if (!filaVazia(c)) {
        Celula *morta = c->prox;
        *x = morta->conteudo[0];
        *y = morta->conteudo[1];
        if (morta->prox == c) {
            c->prox = NULL;
        } else {
            c->prox = morta->prox;
        }
        free(morta);
    }
};

int filaVazia(Celula *c) {
    return c->prox == NULL;
};

int filaCheia() {
    Celula *c;
    c = malloc(sizeof(Celula));
    if (c == NULL)
        return 1;
    free(c);
        return 0;
};