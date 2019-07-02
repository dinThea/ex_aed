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
    return tamFila(q) < MAX_SIZE;
}

void insereFila(Fila *q, char x) {
    if (!filaCheia(q)) {
        if (q->fim == MAX_SIZE-1) {
            q->fim = 0;
            q->v[q->fim] = x;
        } 
        return q->v[++fila->fim];
    }
}

char removeFila(Fila *q, char x) {
    if (!filaVazia(q)) {
        if (q->inicio == MAX_SIZE-1) {
            q->inicio = 0;
            return q->v[q->inicio];
        } 
        return q->v[++fila->inicio];
    }
}

int tamFila (Fila *q) {
    if (q->inicio <= q->fim) return q->fim-q->inicio;
    else return (MAX_SIZE - q->inicio) + q->fim;
}