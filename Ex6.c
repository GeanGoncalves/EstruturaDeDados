//Gean Carlos Gonçalves Martins
//2020021262

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define TAM_EVENTO 50

typedef enum {false, true} bool;

typedef struct no {
 char evento[TAM_EVENTO];
 int data;
 struct no *prox;
} noEvento;

noEvento *prim = NULL;
noEvento *ult = NULL;

bool insereEvento(char evento[], int data);
void inicializaEventos();
void imprimeAgenda();
bool removeEvento(int data);

int main() {
    inicializaEventos();
    int opcao = 1;
    
    while(opcao != 3) {
        printf("***LISTA DINAMICA CIRCULAR***\n");
        printf("   ***LAB 6 DE ECOP12***\n");
        printf("\n Digite uma das opcoes abaixo \n");
        printf("1 - imprime eventos em data crescente\n");
        printf("2 - para remover um evento\n");
        printf("3 - para sair da agenda\n");
        printf("Resposta: ");
        scanf("%d", &opcao);
        
        getchar();
        switch(opcao){
        case 1:
            printf("\n>> Agenda crescente: \n");
            imprimeAgenda();
            getchar();
            break;

        case 2:
            printf("\n>> Remocao de um evento: \n");
            printf(">>> Data: dd/mm/aaaa\n");
            
            int data, dia, mes, ano;
            scanf("%d/%d/%d", &dia, &mes, &ano);
            data = (ano-2019)*366+mes*31+dia;
            fflush(stdin);
            
            if (removeEvento(data))
            printf("Data removida!\n");
            
            else
            printf("Data nao encontrada!\n");
            getchar();
            break;

        case 3:
            printf("\n>> Saindo da agenda...\n");
            getchar();
            break;
            default:
            
            printf(">> Opcao invalida: %c\n", opcao);
            break;
            }
        system("cls");
            }
        return 0;
        }

bool insereEvento(char evento[TAM_EVENTO],int data){
    noEvento *aux = NULL;
    noEvento *atual = prim;
    noEvento *novo;
    novo = (noEvento*)malloc(sizeof(noEvento));

    if(prim==NULL){
        prim = novo;
        ult = novo;
        strcpy(novo->evento, evento);
        novo->data = data;
        novo->prox = novo;
    }
    else{
        while(atual->data<data){
        aux = atual;
        atual = atual->prox;
        if(atual == prim)
        break;
        }
        
    if(aux==NULL){
        prim = novo;
        ult->prox = prim;
        }
    
    else{
        aux->prox = novo;
        }
        strcpy(novo->evento, evento);
        novo->data = data;
        novo->prox = atual;
        
    if(atual==prim){
        ult = novo;
        }
    }
    return true;
}

void inicializaEventos(){
char data[20][12] ={
"28/09/2019",
"29/09/2019",
"30/09/2019",
"01/10/2019",
"02/10/2019",
"03/10/2019",
"04/10/2019",
"05/10/2019",
"06/10/2019",
"07/10/2019",
"08/10/2019",
"09/10/2019",
"10/10/2019",
"11/10/2019",
"12/10/2019",
"13/10/2019",
"14/10/2019",
"15/10/2019",
"16/10/2019",
"17/10/2019"
};

char evento[20][TAM_EVENTO]={
"UFC Fight Night: Usman vs. Ponzinibbio",
"UFC 224: Nunes vs. Pennington",
"UFC Fight Night: Barboza vs. Lee",
"UFC on Fox: Poirier vs. Gaethje",
"UFC 223: Khabib vs. Iaquinta",
"UFC Fight Night: Werdum vs. Volkov",
"UFC 222: Cyborg vs. Kunitskaya",
"UFC on Fox: Emmett vs. Stephens",
"UFC Fight Night: Cowboy vs. Medeiros",
"UFC 221: Romero vs. Rockhold",
"UFC Fight Night: Machida vs. Anders",
"UFC on Fox: Jacar� vs. Brunson 2",
"UFC 220: Miocic vs. Ngannou",
"UFC Fight Night: Stephens vs. Choi",
"UFC 219: Cyborg vs. Holm",
"UFC on Fox: Lawler vs. dos Anjos",
"UFC Fight Night: Swanson vs. Ortega",
"UFC 218: Holloway vs. Aldo 2",
"The Ultimate Fighter: A New World Champion Finale",
"UFC Fight Night: Bisping vs. Gastelum"
};

int i=0;
    for(i=0;i<20;i++){
    int x,dia,mes,ano;
        
        ano = (data[i][8]-48)*10+data[i][9]-48-19;
        mes = (data[i][3]-48)*10+data[i][4]-48;
        dia = (data[i][0]-48)*10+data[i][1]-48;
        x = ano*366+mes*31+dia;
        insereEvento(evento[i],x);
    }
}

void imprimeAgenda(){
    int i=0;
    noEvento *atual = prim;

    if(atual!=NULL){
    while(true){
    printf("[%d-%s  -  %d/%d/%d]",i+1,atual->evento,((atual->data%366)%31), (atual->data%366)/31,atual->data/366+2019);
    printf("\n");

    atual = atual->prox;
    i++;
    if(atual==prim)
    break;
    }
    }
}

bool removeEvento(int data){
    noEvento *aux = NULL;
    noEvento *atual = prim;

    if(atual!=NULL){
        while(atual->data!=data){
        aux = atual;
        atual = atual->prox;
        
    if(atual==prim)
        break;
        }
        
    if(atual->data!=data)
        return false;
        
    else{
        if(atual==prim){
        prim = atual->prox;
        ult->prox = prim;
        free(atual);
    }
    else{
        aux->prox = atual->prox;
        
    if(atual==ult){
        ult = aux;
    }
    free(atual);
    }
    return true;
    }
    }
    else
    return false;
}


