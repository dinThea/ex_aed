#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct noh {
    Cont conteudo;
    int profundidade;
    struct noh *pai; 
    struct noh *esq;
    struct noh *dir;
} Noh;

Arvore criaArvore(Cont conteudo) {

    Arvore arvore = (Arvore) malloc(sizeof(Noh));

    arvore->pai = NULL;
    arvore->esq = NULL; 
    arvore->dir = NULL;
    arvore->profundidade = 0;
    arvore->conteudo = conteudo;

    return arvore;
}

Noh* append(Noh *no, Cont conteudo, int direcao) {
    
    Noh* novo = (Noh*)malloc(sizeof(Noh));
    if (direcao) no->esq = novo;
    else no->dir = novo;
    (novo)->profundidade = no->profundidade+1;
    (novo)->pai = no;
    (novo)->esq = NULL; 
    (novo)->dir = NULL;
    (novo)->conteudo = conteudo;

    return novo;

}

void popular(Noh *no, int profundidade, int val) {

    if (no->profundidade < profundidade) {
        Noh *esq = append(no, val+1, 1);
        popular(esq, profundidade, val+1);
        Noh *dir = append(no, val+1, 0);
        popular(dir, profundidade, val+1);
    }
}

void imprimeERD(Noh *no) {
    if (no->esq != NULL) imprimeERD(no->esq);
    printf ("%d\n", no->conteudo); 
    if (no->dir != NULL) imprimeERD(no->dir);
}

int altura(Noh *no) {
    Noh *x;
    Noh *p[100];
    int t = 0; 
    x = no;
    int alturamax = 0;

    while (x != NULL || t > 0) {
        if (x != NULL) {
            p[t++] = x; // empilha x
            x = x->esq; // visita filho esquerdo de x
        } else {
            x = p[--t]; // desempilha x
            if (x->profundidade > alturamax) alturamax = x->profundidade;
            x = x->dir; // visita o filho direito de x    
        }
    }

    return alturamax;
}

void imprimeIterativoPilha (Noh *r, int op) {
    
    Noh *x;
    Noh *p[100];
    int t = 0; 
    x = r;

    while (x != NULL || t > 0) {
        if (x != NULL) {
            switch (op) {
                case 0: // ERD
                    p[t++] = x; // empilha x
                    x = x->esq; // visita filho esquerdo de x
                break;

                case 1: // RED
                    printf("(%d, %d)\n", x->conteudo, x->profundidade);
                    p[t++] = x; // empilha x
                    x = x->esq;
                break;

                case 2: // EDR
                    p[t++] = x; // empilha x
                    if (x->dir != NULL) p[t++] = x->dir; // empilha direita
                    x = x->esq; // visita filho esquerdo de x
                break;
            }
        }
        else {
            switch (op) {
                case 0: // ERD
                    x = p[--t]; // desempilha x
                    printf("(%d, %d)\n", x->conteudo, x->profundidade);
                    x = x->dir; // visita o filho direito de x
                break;

                case 1: // RED
                    x = p[--t]; // desempilha x
                    x = x->dir; // visita o filho direito de x
                break;
                
                case 2: // EDR
                    x = p[--t]; // desempilha x que pode ser no anterior caso nao tenha chegado numa ponta ou a raiz caso tenha
                    if (x->dir == NULL && x->esq == NULL) printf("(%d, %d)\n", x->conteudo, x->profundidade); // se for raiz
                    else {
                        
                        p[t++] = x; // empilha x
                        if (x->dir != NULL) p[t++] = x->dir; // empilha direita
                        x = x->esq; // visita filho esquerdo de x
                    } //se for direita normal
                break;
            }
        }
    }
}

void appendBalanceado(Noh *no, Cont conteudo);