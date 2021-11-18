
#include <cstring>
/* declaracao do no */
	struct noFila {
        int dado;       //tipo do elemento da fila
        struct noFila *prox;
	};

/*Definição do tipo de dado pilha */
	typedef struct noFila* TipoFila;

void init(TipoFila *ini, TipoFila *fim)
{
*ini  = NULL;
*fim = NULL;
}

int isEmpty(TipoFila ini,TipoFila fim)
{
if ((ini == NULL) && (fim == NULL))
	return(1);
else
	return(0);
}


void enqueue( TipoFila *ini, TipoFila *fim, int v)
{
TipoFila novo;
novo=(TipoFila ) malloc (sizeof(struct noFila));
if (novo==NULL)
	 cout << "Fila Cheia \n";
else  {
	 novo->dado = v;
	 novo->prox=NULL;
	 if (isEmpty(*ini, *fim))
	     *ini = novo;
	 else
	     (*fim)->prox= novo;

     *fim=novo;
	}
}

int dequeue( TipoFila *ini, TipoFila *fim, int v)
{
TipoFila aux = *ini;
if (isEmpty(*ini, *fim)){
    return 0;
}
else{
    v = aux->dado;
    *ini = aux->prox;
    if (*ini == NULL)
        *fim = NULL;
    free(aux);
    return 1;
}
}
