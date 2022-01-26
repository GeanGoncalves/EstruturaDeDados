//Gean Carlos Gonçalves Martins
//2020021262

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{false, true} bool;

typedef struct {
    float valor;
    char item[20];
    int prox;
} noItens;

noItens listaItens[20];
    int prim=-1;
    int dispo=0;

void inicializaLista()
{
    int i;

    for(i=0;i<20;i++)
    {
    listaItens[i].prox = i+1;
    }
    listaItens[i].prox = -1;
}

bool insereItens(char item[20],float valor)
{
    int inse,ant,atual;
    
    if(dispo == -1)
    return false;
    
    else
    {
    ant = -1;
    atual = prim;
    inse = dispo;
    
    while((atual!=-1)&&(strcmp(listaItens[atual].item,item)<0))
    {
    ant = atual;
    atual = listaItens[atual].prox;
    }
    dispo = listaItens[dispo].prox;
    
    if(ant==-1)
    prim=inse;
    
    else
    listaItens[ant].prox = inse;
    strcpy(listaItens[inse].item,item);
    listaItens[inse].valor = valor;
    listaItens[inse].prox = atual;
    return true;
    }
}

void mostraLista()
{
    int pos = prim;
    int i;
    
    while(pos!=-1)
    {
    printf("Item:%s, Valor: %.2f,Proximo:%d \n",listaItens[pos].item,listaItens[pos].valor,listaItens[pos].prox);
    pos = listaItens[pos].prox;
    i++;
    }
}

bool removeItem(char item[20])
{
    int ant, atual;
    atual = prim;
    ant = -1;
    
    while((atual!=-1)&&(strcmp(listaItens[atual].item,item)!=0))
    {
    ant = atual;
    atual = listaItens[atual].prox;
    }
    
    if(atual == -1)
    return false;
    
    else
    {
    if(ant == -1)
    prim = listaItens[atual].prox;
    
    else
    listaItens[ant].prox = listaItens[atual].prox;
    listaItens[atual].prox = dispo;
    dispo = atual;
    return true;
    }
}

bool buscaItem(char item[20])
{
    int pos = prim;

    while((pos!=-1)&&(strcmp(listaItens[pos].item,item)!=0))
    {
    pos = listaItens[pos].prox;
    }
    
    if(strcmp(listaItens[pos].item,item)==0)
    return true;
    else
    return false;
    return pos;
}

int main()
{
    int i=0,aux=0,j;
    float precos;
    char itens[20],busca[20],remove[20];
    
    inicializaLista();
    for(i=0;i<20;i++)
    {
    printf("\tAtividade de ECOP02\n");
    printf("Informe o item %d, e seu preco: ", i+1);
    scanf("%s %f",&itens,&precos);
    
    if(buscaItem(itens))
    {
    printf("\nEsse item ja esta na lista\nPor favor, informe outro item!\n");
    i--;
    }
    else
    insereItens(itens,precos);
    }

    mostraLista();
    printf("\nInforme um item a ser procurado: ");
    scanf("%s",&busca);
    
    if(buscaItem(busca))
    printf("\nO item esta na lista.\n");
    
    else
    printf("\nO item nao esta na lista.\n");
    printf("Informe um item a ser retirado da lista: ");
    scanf("%s",&remove);
    removeItem(remove);
    
    if(removeItem(remove))
    printf("\nItem removido!\n");
    mostraLista();

    return 0;
}
