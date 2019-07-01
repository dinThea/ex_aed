#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"
#define TAMANHO 100

typedef struct pilha_t  
{
    int t;
    char pilha[TAMANHO];
}Pilha;

int pilhaVazia(Pilha *s) {
    return !(s->t >= 0);
}

int pilhaCheia(Pilha *s) {
    return !(s->t < TAMANHO-1);
}

Pilha *criaPilha(){
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->t = -1;
    return pilha;
}

void empilha (Pilha *s, char x){
    if (!pilhaCheia(s)){
        s->pilha[++(s->t)] = x;
    }
}

char desempilha(Pilha *s){
    if (!pilhaVazia(s)){
        return s->pilha[(s->t)--];
    }
}

int tamPilha(Pilha *s){
    return (s->t+1);
}

char consultaTopo(Pilha *s){
    if (!pilhaVazia(s))
        return (s->pilha[s->t]);
    else return -1;
}

void Infix2Posfix(char *infix, char *posfix){
    
    Pilha *s = criaPilha();
    int pos = 0;

    for (int i = 0; i < strlen(infix); i++) {
        switch (infix[i])
        {
        case '(':
            empilha(s, infix[i]);
            break;
        case ')':
            while (!pilhaVazia(s) && consultaTopo(s) != '(')
                posfix[pos++] = desempilha(s);
            desempilha(s);
            break;
        case '+':
        case '-':
            while (!pilhaVazia(s) && consultaTopo(s) != '(')
                posfix[pos++] = desempilha(s); 
            empilha(s, infix[i]); 
            break;
        case '*':
        case '/':
            while (!pilhaVazia(s) && consultaTopo(s) != '(' && consultaTopo(s) != '+' && consultaTopo(s) != '-')
                posfix[pos++] = desempilha(s); 
            empilha(s, infix[i]);
            break;
        default:
            posfix[pos++] = infix[i];
            break;
        }
    }
    while (!pilhaVazia(s)) {
        char ch = desempilha(s);
        if (consultaTopo(s) != '('){
            posfix[pos++] = ch;
        }
    }
    posfix[pos++] = '\0';
    free(s);

}

double solvePosfix(char *posfix){

    double *acc = (double*) malloc (sizeof(double) * strlen(posfix));
    int last = -1; 

    for (int i = 0; i < strlen(posfix); i++){
        switch (posfix[i])
        {
        case '+':
            acc[last-1] = acc[last-1]+acc[last]; 
            last--;
            break;
        case '-':
            acc[last-1] = acc[last-1]-acc[last]; 
            last--;
            break;
        case '/':
            acc[last-1] = acc[last-1]/acc[last]; 
            last--;
            break;
        case '*':
            acc[last-1] = acc[last-1]*acc[last]; 
            last--;
            break;
        default:
            acc[++last] = (double) (posfix[i] - 'A' + 1);
            break;
        }
    }

    return acc[last];
}