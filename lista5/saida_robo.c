#include "fila_lista.h" //"fila.h"
#include <stdio.h>
#define M 3
#define N 4

int testeValidade (int x, int y, int m, int n) {
    return (x<m && x>=0 && y <n && y>=0);
}
int main () {

    int tabuleiro[M][N] = {0,0,0,1,0,1,0,0,0,0,1,0};
    int resolucao[M][N];
    int m = M, n = N;
    for (int i = 0; i<m; i++) for (int j=0; j<n; j++) resolucao[i][j] = -1;

    Celula *cabeca = criaFila();
    insereFila(cabeca, 0, 0);

    while (!filaVazia(cabeca)) {

        int x, y;
        removeFila(cabeca, &x, &y);
        resolucao[x][y]+=1;
        int direcoes[4][2] = {-1,0,1,0,0,1,0,-1};

        for (int i = 0; i < 4; i++) {
            if (testeValidade(x+direcoes[i][0], y+direcoes[i][1], m, n)) {
                
                int xa = x+direcoes[i][0], ya = y+direcoes[i][1];

                if (((tabuleiro[xa][ya]) == 0) && ((resolucao[xa][ya]) < 0)) {
                    resolucao[xa][ya]+=(resolucao[x][y]+1);
                    insereFila(cabeca, xa, ya);
                }    
            } 
        }

    }

    printf ("Tabuleiro de distancias:\n\n");
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) printf ("%d ", resolucao[i][j]);
        printf ("\n");
    }
    if (resolucao[m-1][n-1] == -1) printf ("\nO robo nao cumpriu o objetivo\n");
    else printf ("\nA distancia para o objetivo foi: %d\n", resolucao[m-1][n-1]);

    return 0;

}