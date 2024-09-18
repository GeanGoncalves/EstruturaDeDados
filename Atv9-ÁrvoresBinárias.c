//Gean Carlos Gonçalves Martins
//2020021262

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct no{
	char cep[9];
	char uf[3];
	char cidade[31];
	char logradouro[61];
	struct no *esq;
	struct no *dir;
}noCEP; 

noCEP *arvBinaria;

int quant = 0;
int cont = 0;

void inserirNoArvoreBinaria(FILE *arq){
	char linha[200];
	char *substring;
	int i;
	noCEP *ant = NULL;
	noCEP *atual = arvBinaria;
	noCEP *novo;

    novo = (noCEP *) malloc(sizeof(noCEP));

    fgets(linha, 200, arq);

    substring = strtok(linha, "\t");

    if(substring != NULL) {
    strcpy(novo->cep, substring);
    }
    substring = strtok(NULL, "\t");

    if(substring != NULL)
    strcpy(novo->uf, substring);
    substring = strtok(NULL, "\t");

    if(substring != NULL)
    strcpy(novo->cidade, substring);
    substring = strtok(NULL, "\t");

    if(substring != NULL)
    strcpy(novo->logradouro, substring);

    novo->esq = NULL;
    novo->dir = NULL;

    printf("\nLido os dados de um cep: \n");
    imprimeNoCEP(novo);

    while((atual != NULL) && (strcmp(novo->cep, atual->cep) != 0)){
    ant = atual;
       
    if(strcmp(novo->cep, atual->cep) < 0){
    atual = atual->esq;
    }
    else{
    atual = atual->dir;
    }
    }

    if(ant == NULL){ 
    arvBinaria = novo;
    }
    else{
    if(atual == NULL){
    if(strcmp(novo->cep, ant->cep) < 0){
    ant->esq = novo;
    }
    else{
    ant->dir = novo;
    }
    }
    }
    quant++; 
}

void imprimeNoCEP(noCEP *n){
	if(cont<10){
	printf("\t--CEP: %s\n", n->cep);
	printf("\t--UF: %s\n", n->uf);
	printf("\t--Cidade: %s\n", n->cidade);
	printf("\t--Logradouro: %s\n", n->logradouro);
	}
}

void imprimePreOrdemArvBB(noCEP *n){
    if(n != NULL){
    imprimeNoCEP(n);
    cont++;
    imprimePreOrdemArvBB(n->esq);
    imprimePreOrdemArvBB(n->dir);
    }
}

void imprimeEmOrdemArvBB(noCEP *n){
    if(n != NULL){
    imprimeEmOrdemArvBB(n->esq);
    imprimeNoCEP(n);
    cont++;
    imprimeEmOrdemArvBB(n->dir);
    }
}

void imprimePosOrdemArvBB(noCEP *n){
    if(n != NULL){
    imprimePosOrdemArvBB(n->esq);
    imprimePosOrdemArvBB(n->dir);
    imprimeNoCEP(n);
    cont++;
    }
}

void buscarArvoreBinaria(noCEP *c, char busca[9]){
	if(c != NULL && cont == 0){
	buscarArvoreBinaria(c->esq, busca);
	buscarArvoreBinaria(c->dir, busca);
	if(strcmp(c->cep, busca) == 0){
	imprimeNoCEP(c);
	cont++;
	}
	}
}

int main(int argc, char *argv[]){
    FILE *arq;
    int opcaoMenu;
    char cepProcurado[9];
    noCEP *cepEncontrado;

    //inicializa a arvore
    arvBinaria = NULL;

    //o arquivo eh lido e inserido os elementos na arvore
    arq = fopen("baseCep.txt", "r");

    if(!arq){
        printf("O arquivo nao pode ser aberto.\n");
        exit(1);
    }//end if(!arq)

    printf("\nInserindo elementos na arvore... \n");
    while(!feof(arq) && quant<12){
        //para cada linha do arquivo pe chamada
        //a funcao de insercao na arvore binaria
        inserirNoArvoreBinaria(arq);
    }//end while(!feof(arq))
    fclose(arq);

    //menu para caminhamento na arvore de ceps
    opcaoMenu = 1;
    while(opcaoMenu != 4){
        quant = 0;

        printf("|Selecione uma das opcoes do menu: |\n");
        printf("|1 - Pre-ordem                     |\n");
        printf("|2 - Em-ordem                      |\n");
        printf("|3 - Pos-ordem                     |\n");
        printf("|4 - Sair                          |\n\n");
        printf(">");

        scanf("%d", &opcaoMenu);
        switch(opcaoMenu){
            case 1:
            	cont = 0;
                printf("Imprime em pre-ordem: \n");
                imprimePreOrdemArvBB(arvBinaria);
   	            printf("\n");
		        break;
            case 2:
            	cont = 0;
                printf("Imprime em em-ordem: \n");
	            imprimeEmOrdemArvBB(arvBinaria);
               	printf("\n");
	            break;
            case 3:
            	cont = 0;
                printf("Imprime em pos-ordem: \n");
	            imprimePosOrdemArvBB(arvBinaria);
                printf("\n");
                break;
            case 4:
                printf("Saindo do menu impressoes: ");
                break;
        }
    }

    // chamada à busca por um cep
	printf("\n>>> Busca por um cep: \n");
	printf(">> Digite um cep: ");
	scanf("%s", cepProcurado);
	cont = 0;
	buscarArvoreBinaria(arvBinaria,cepProcurado);
	
    if(cont == 0){
	printf("\n>>CEP nao encontrado do banco de dados\n");
	}//end if
	printf("\n>>Encerrando o programa...\n");
	free(arvBinaria);
	system("PAUSE");
	return 0;
}//end main
