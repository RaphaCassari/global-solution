#include <iostream>
#include <locale>

using namespace std;

#include <stdlib.h>

#define NC 16  // número de caracteres para armazenar as coordenadas

struct Boia{
    int hashcode;
    char coordenada[NC];
    float temperatura;
    float salinidade;
    int alerta;
};
typedef struct Boia TipoBoia;

/* ********TAREFA 1 *************/
#include "TipoFilaCoordenadas.h"

/* ********TAREFA 2 *************/
#include "TipoABB_Boia.h"


void geraFila(TipoArvore  p, TipoFilaCoordenadas *ini, TipoFilaCoordenadas *fim)
{
  if (p!=NULL){
    if (p->dado.alerta){
        enqueue(ini, fim, p->dado.coordenada);
        p->dado.alerta = 0;
    }
   	if(p->esq!=NULL)
       geraFila(p->esq, ini, fim);
   	if(p->dir!=NULL)
       geraFila (p->dir, ini, fim);
     }
}

int main()   {

setlocale(LC_ALL, "");
TipoArvore tree;
tree = NULL;
TipoFilaCoordenadas ini, fim;
int opcao;
init(&ini, &fim);
TipoBoia s;
char hashcode[5];
char coord[NC];
int i,hashcodeInt;

char hc[9][NC] = {"-23.50°-45.21°","-25.02°-47.93°","-22.90°-43.17°","-24.90°-42.17°","-25.10°-44.17°","-22.40°-39.04°",
"-24.40°-36.92°","-26.89°-44.07°","-27.99°-46.17°"};
cout << " Iniciando o cadastramento de 9 boias já existentes...\n" ;
for (i=0; i<9; i++){
            hashcode[0] = hc[i][1];
            hashcode[1] = hc[i][2];
            hashcode[2] = hc[i][8];
            hashcode[3] = hc[i][9];
            hashcode[4] = '\0';
            hashcodeInt = atoi(hashcode);
            cout << hc[i] << " salinidade: ";
            cin >> s.salinidade;
            cout << hc[i] << " temperatura: ";
            cin >> s.temperatura;
            strcpy(s.coordenada,hc[i]);
            s.hashcode = hashcodeInt;
            s.alerta = 0;
            insere(&tree, s);
}
do {
    cout <<endl;
    cout << " 1- inserir mais 1 boia \n 2- Lista Ordem Descrescente  \n 3- Atualiza Medidas\n";
    cout << " 4- Inicia visita aos locais \n 5- Consulta medidas de 1 boia  \n 0- Sair\n";
    cin >> opcao;
    cin.ignore();
    switch(opcao){
        case 0:
            cout << "******** Sistema de Monitoramento Encerrando ***************" << endl;
            break;
        case 1:
            cout << " Digite coordenadas da boia a ser inserida no sistema: ";
//Lê do teclado as coordenadas da boia e gera hash code
//insere na ABB o registro da boia
            break;
        case 2:
            cout <<"\n******************* Lista Ordem Descrescente **********"<<endl;
// implemente essa função no arquivo header TipoABB_Boia.h
// A função deve apresentar hash code e coordenada de cada boia
            lista_em_ordemD(tree);
            cout <<"*********************************************************"<<endl;
            break;
        case 3:
            atualizaMedidas(tree);
            cout << "Gera uma fila com as coordenadas das boias \n";
//faz a chamada da função geraFila() implementada no início deste arquivo
            break;
        case 4:
            cout << "Inicia visita dos locais com coordenadas na fila \n";

            if (isEmpty(ini,fim))
                cout << "Não foi ainda gerada fila de locais\n";
            else{
//Retira 1 local da fila para deslocamento da equipe de visita
//Repete a ação anterior até que a fila seja esvaziada

            }
            break;
        case 5:
            cout << "hash code \t Coordenada\n";
            lista_em_ordemD(tree);
            cout << "escolha o hash code do sensor que deseja consultar: as últimas medidas do solo: ";
            cin >> hashcodeInt;
// implemente a função consulta no arquivo header TipoABB_Boia.h
            if (!consulta(tree, hashcodeInt))
                cout << "Não há sensor identificado com esse código\n";
            break;
        default: cout << "Opção inválida\n";
            }
}while (opcao !=0);


    return 0;
}

