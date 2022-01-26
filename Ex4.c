//Gean Carlos Gonçalves Martins
//2020021262

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {false,true} bool;

typedef struct no
{
char nome[50];
char edit[50];
char clas[50];
int ano;
int isbn;
struct no *prox;
}noLivro;

noLivro *prim=NULL;

bool buscaLivro(int livro)
{
    noLivro *marcador;
    marcador=prim;

    if(prim==NULL){
    return false;
    }

    while(marcador!=NULL){
    if(marcador->isbn==livro){
    return true;
    }
    marcador=marcador->prox;
    }
    return false;
}

bool insereLivro(noLivro livro)
{
    noLivro *novo=(noLivro*)malloc(sizeof(noLivro));
    noLivro *marcador;

    if(prim==NULL){
    prim=novo;
    *novo=livro;
    return true;
    }
    if(buscaLivro(livro.isbn)==true){
    return false;
    }

    else{
    marcador=prim;
    while(marcador->prox!=NULL){
     marcador=marcador->prox;
    }
    *novo=livro;
    marcador->prox=novo;
    return true;
    }
}

bool removeLivro(int livro)
{
    noLivro *marcador,*aux;
    if(buscaLivro==false){
    return false;
    }

    else{
    marcador=prim;
    aux=prim;
    while(marcador->isbn!=livro){
    aux=marcador;
    marcador=marcador->prox;
    }
    aux->prox=marcador->prox;
    free(marcador);
    return true;
    }
}

void imprimeLista(void)
{
    noLivro *marcador;
    marcador=prim;

    while(marcador!=NULL){
    printf("\n[%s - %s - %s - %d - %d]",marcador->nome,marcador->edit,marcador->clas,marcador->ano,marcador->isbn);
    marcador=marcador->prox;
    }
}

void apagaPrim(void)
{
    noLivro *aux,*marcador;
    marcador=prim;
    aux=prim;

    while(marcador!=NULL){
    aux=marcador;
    marcador=marcador->prox;
    free(aux);
    }
}

int main()
{
    noLivro livro;
    int ano,isbn,aux;
    char nome[50],edit[50],clas[50];

    for(aux=0;aux<5;aux++){
    printf("\n        Atividade de Estrutura de Dados");
    printf("\nInforme o nome do livro: ");
    scanf("%s",nome);

    printf("Informe a editora do livro: ");
    scanf("%s",edit);

    printf("Informe a classificacao do livro: ");
    scanf("%s",clas);

    printf("Informe o ano de lancamento do livro: ");
    scanf("%d",&ano);

    printf("E por ultimo,informe o ISBN do livro: ");
    scanf("%d",&isbn);
        
    strcpy(livro.nome,nome);
    strcpy(livro.edit,edit);
    strcpy(livro.clas,clas);
    livro.ano=ano;
    livro.isbn=isbn;
    livro.prox=NULL;
    
    if(insereLivro(livro)==false){
    printf("\nInfelizmente, foi possivel inserir esse livro na lista\n");
    aux--;
    }

    else{
    insereLivro(livro);
    }
    }
    printf("\n[NOME - EDITORA - CLASSIFICACAO - ANO - ISBN]");
    imprimeLista();
    aux=0;
    
    while(aux==0){
    printf("\n\nInforme o ISBN do livro a ser retirado da Lista");
    scanf("%d",&isbn);
    if(removeLivro(isbn)==false){
    printf("\nInfelizmente, nao foi possivel remover esse livro da lista");
    }
    else{
    aux=1;
    printf("\nLivro retirado com sucesso");
    }
    }
    
    printf("\n[NOME - EDITORA - CLASSIFICACAO - ANO - ISBN]");
    imprimeLista();
    apagaPrim();
}
