#include <string.h>
#include <stdlib.h>
#include "fila.h"
#define MAX_SIZE 100 

typedef struct fila_t {
    char v[MAX_SIZE];
    int inicio;
    int fim;
} Fila;

Fila *criaFila() {
    Fila *fila = (Fila*) malloc (sizeof(Fila));
    fila->inicio=0;
    fila->fim=0;
}

int filaVazia(Fila *q) {
    return fila->inicio==fila->fim;
}

int filaCheia(Fila *q) {
    return fila->fim == strlen(v)-1;
}

void insereFila(Fila *q, char x) {
    if (!filaCheia(q)) q->v[++fila->fim] = x;
}

char removeFila(Fila *q, char x) {
    if (!filaVazia(q)) return q->v[++fila->inicio];
}

int tamFila (Fila *q) {
    return q->fim - q->inicio;
}