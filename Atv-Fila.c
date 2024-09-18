//Gean Carlos Gonçalves Martins
//2020021262

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef enum {false, true} bool;
typedef struct no
{
int voo;
char n[30];
struct no *prox;
}noAviao;
noAviao *ult=NULL;

void quantidade(){ 
    noAviao *aux;
    int cont=0;
    aux=ult;
    
    printf("\nQUANTIDADE DE VOOS NA FILA!");
    
    while(aux!=NULL){
    cont=cont+1;
    aux=aux->prox;
    }
    printf("\nNo momento possui %d voos na fila de espera!\n",cont);
    printf("\n");
    return;
}

bool decolagem(){
    noAviao *aux;
    
    if(ult==NULL){
    return false;
    }
    
    else{
    aux=ult;
    ult=aux->prox;
    free(aux);
    return true;
    }
}

void adicionar(char *n,int voo){
    noAviao *novo=(noAviao*)malloc(sizeof(noAviao));
    noAviao *aux;
    
    strcpy(novo->n,n);
    novo->voo=voo;
    novo->prox=NULL;
    
    if(ult==NULL){
    ult=novo;
    }
    aux=ult;
    
    if(aux==novo){
    return;
    }
    
    else{
    while(aux->prox!=NULL){
    aux=aux->prox;
    }
    aux->prox=novo;
    return;
    }
}

void fila(){
    noAviao *aux;
    aux=ult;
    
    printf("\nFILA DE ESPERA DOS VOOS!");
    while(aux!=NULL){
    printf("\n[Voo %s - Codigo %d]",aux->n,aux->voo);
    aux=aux->prox;
    }
    printf("\n\n");
}

int main(){
    char n[30];
    int menu,voo;
    
    printf("\nLAB 8 DE ECOP12");
    do{
    printf("\nMENU\n");
    printf("1 - Para adicionar voo\n");
    printf("2 - Para autorizar a decolagem voo\n");
    printf("3 - Para ver a quantidade de voos\n");
    printf("4 - Para ver a fila de voos\n");
    printf("5 - Para sair\n");
    printf("Resposta: ");
    scanf("%d", &menu);
    
    getchar();
    switch(menu)
    {
    case 1:
    printf("\nPor favor, digite o nome do voo e respectivamente, o seu codigo:\n");
    scanf("%s",n);
    scanf("%d",&voo);
    adicionar(n,voo);
    Sleep(1000);
    system("cls");
    break;
        
    case 2:
    if(decolagem()==true){
    printf("\nO Voo foi autorizado para decolagem com sucesso!\n");
    printf("Boa viagem!!!\n");
    Sleep(6000);
    system("cls");
    }
    else{
    printf("\nNao possui nenhum voo na fila de espera para autorizar a decolagem!\n");
    }
    Sleep(6000);
    system("cls");
    break;
        
    case 3:
    quantidade();
    Sleep(6000);
    system("cls");
    break;
        
    case 4:
    fila();
    Sleep(6000);
    system("cls");
    break;
        
    case 5:
    Sleep(1000);
    system("cls");
    break;
    default:

    printf("\nOpcao invalida!!!\n");
    printf("Por favor, digite um numero de 1 ate 5\n");
    Sleep(2000);
    system("cls");
    }
    }
    while(menu!=5);
    while(decolagem()!=false){
    decolagem();
    }
    
}
