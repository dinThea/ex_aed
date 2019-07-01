typedef struct pilha_t Pilha;

Pilha *criaPilha();
void empilha(Pilha *s, char x);
char desempilha(Pilha *s);
char consultaTopo(Pilha *s);
int pilhaVazia(Pilha *s);
void imprimePilha(Pilha *s);
int tamPilha(Pilha *s);
Pilha *liberaPilha(Pilha *s);
void Infix2Posfix(char *infix, char *posfix);
double solvePosfix(char *posfix);