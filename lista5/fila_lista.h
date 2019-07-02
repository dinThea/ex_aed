typedef struct celula_t Celula;
Celula *criaFila();
void insereFila(Celula *c, int x, int y);
void removeFila(Celula *c, int *x, int *y);
int filaVazia(Celula *c);
int filaCheia();
void imprimeFila(Celula *c);
int tamFila(Celula *c);
Celula *liberaFila(Celula *c);