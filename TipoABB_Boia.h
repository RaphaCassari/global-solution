struct noInt {
	   int dado;
	   struct noInt *esq,*dir;
	   };

typedef struct noInt* TipoArvore;

void insere(TipoArvore *p, int info) {
TipoArvore novo;
if (*p==NULL){
  novo=(TipoArvore) malloc(sizeof(struct noInt));
  if (novo!=NULL){
    novo->dado = info;
    novo->dir = NULL;
    novo->esq = NULL;
    *p=novo;
    }
  }
else{
  if (info < (*p)->dado)
    insere(&(*p)->esq,info);
  else
    insere(&(*p)->dir,info);
  }
}

/* **** Implemente essa função ********* */
void lista_em_ordemD(TipoArvore  p) {
}

// Essa função está correta apenas depois de alterar o dado da ABB para ser Registro Boia
void atualizaMedidas(TipoArvore  p)
{
float antes;
if (p!=NULL){
    if(p->esq!=NULL)
        atualizaMedidas(p->esq);
    cout << "atualiza medida do sensor com coordenadas: " << p->dado.coordenada << endl;
    antes = p->dado.salinidade;
    cout << "Medida de salinidade: ";
    cin >> p->dado.salinidade;
    if ((p->dado.salinidade - antes)/ antes > 0.2)
        p->dado.alerta = 1;
    antes = p->dado.temperatura;
    cout << "Medida de temperatura: ";
    cin >> p->dado.temperatura;
    if ((p->dado.temperatura - antes)/ antes > 0.2)
       p->dado.alerta = 1;
    if(p->dir!=NULL)
        atualizaMedidas(p->dir);
     }
}

/* **** Implemente essa função ********* */
int consulta(TipoArvore p, int info) {

}
