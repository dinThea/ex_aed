#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {

    int valor[] = {1,2,3,4,5,6}; // 15.5
    char *infix = "(A+B)*D+E/(F+A*D)+C"; //AB+D*EFAD*+/+C+
    char *posfix = (char*) malloc(sizeof(char) * (strlen(infix)+1));
    Infix2Posfix(infix, posfix);

    printf ("%s %lf\n", posfix, solvePosfix(posfix));
}