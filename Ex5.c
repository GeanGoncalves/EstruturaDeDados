//Gean Carlos Gonçalves Martins
//2020021262

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define TAM_PRODUTO 50
#define TAM_CODIGO 10
#define QTD_PRODS 40


typedef enum {false, true} bool;
typedef struct no
{
	char produto[TAM_PRODUTO];
	char codigo[TAM_CODIGO];
	int quantidade;
	struct no *prox;
	struct no *ant;
} noProduto;


noProduto *prim = NULL;
noProduto *ult = NULL;


bool insereProduto(noProduto *novo)
{
    noProduto *marcador,*prox;
    if(prim==NULL){
        ult=novo;
        prim=novo;
        novo->prox=NULL;
        novo->ant=NULL;
        return true;
    }
    prox=prim;
    if(strcmp(novo->produto,prim->produto)<0){
        novo->prox=prim;
        prim->ant=novo;
        novo->ant=NULL;
        prim=novo;
        return true;
    }
    while((prox->prox!=NULL)&&(strcmp(novo->produto,prox->produto)>0)){
        prox=prox->prox;
    }
    if(prox->prox==NULL){
        novo->prox=NULL;
        novo->ant=prox;
        prox->prox=novo;
        ult=novo;
        return true;
    }
    else{
        novo->prox=prox->prox;
        novo->prox->ant=novo;
        novo->ant=prox;
        prox->prox=novo;
        return true;
    }
}
void inserirLista()
{
  char produtos[QTD_PRODS][TAM_PRODUTO] = {
    "SET 7 BABUSHKA NESTING BOXES",
    "GLASS STAR FROSTED T-LIGHT HOLDER",
    "HAND WARMER UNION JACK",
    "HAND WARMER RED POLKA DOT",
    "ASSORTED COLOUR BIRD ORNAMENT",
    "POPPY'S PLAYHOUSE BEDROOM",
    "POPPY'S PLAYHOUSE KITCHEN",
    "FELTCRAFT PRINCESS CHARLOTTE DOLL",
    "IVORY KNITTED MUG COSY",
    "BOX OF 6 ASSORTED COLOUR TEASPOONS",
    "BOX OF VINTAGE JIGSAW BLOCKS",
    "BOX OF VINTAGE ALPHABET BLOCKS",
    "HOME BUILDING BLOCK WORD",
    "LOVE BUILDING BLOCK WORD",
    "RECIPE BOX WITH METAL HEART",
    "DOORMAT NEW ENGLAND",
    "JAM MAKING SET WITH JARS",
    "RED COAT RACK PARIS FASHION",
    "YELLOW COAT RACK PARIS FASHION",
    "BLUE COAT RACK PARIS FASHION",
    "BATH BUILDING BLOCK WORD",
    "ALARM CLOCK BAKELIKE PINK",
    "ALARM CLOCK BAKELIKE RED",
    "ALARM CLOCK BAKELIKE GREEN",
    "PANDA AND BUNNIES STICKER SHEET",
    "STARS GIFT TAPE",
    "INFLATABLE POLITICAL GLOBE",
    "VINTAGE HEADS AND TAILS CARD GAME",
    "SET/2 RED RETROSPOT TEA TOWELS",
    "ROUND SNACK BOXES SET OF4 WOODLAND",
    "SPACEBOY LUNCH BOX",
    "LUNCH BOX I LOVE LONDON",
    "CIRCUS PARADE LUNCH BOX",
    "CHARLOTTE BAG DOLLY GIRL DESIGN",
    "RED TOADSTOOL LED NIGHT LIGHT",
    "SET 2 TEA TOWELS I LOVE LONDON",
    "VINTAGE SEASIDE JIGSAW PUZZLES",
    "MINI JIGSAW CIRCUS PARADE",
    "MINI JIGSAW SPACEBOY",
    "MINI PAINT SET VINTAGE"
  };

  char codigos[QTD_PRODS][TAM_CODIGO] = {
    "22752","21730","22633","22632","84879","22745","22748","22749","22310","84969","22623",
    "22622","21754","21755","21777","48187","22960","22913","22912","22914","21756","22728",
    "22727","22726","21724","21883","10002","21791","21035","22326","22629","22659","22631",
    "22661","21731","22900","21913","22540","22544","22492"
  };

  int quantidades[QTD_PRODS] = {
    2,6,6,6,32,6,6,8,6,6,3,2,3,3,4,4,6,3,3,3,3,24,24,12,12,24,48,24,18,24,24,24,
    24,20,24,24,12,24,24,36
  };

  int i;
  noProduto *novo;

  for(i=0;i<QTD_PRODS;i++){
    novo=(noProduto*)malloc(sizeof(noProduto));
    novo->prox=NULL;
    novo->ant=NULL;
    strcpy(novo->produto,produtos[i]);
    strcpy(novo->codigo,codigos[i]);
    novo->quantidade=quantidades[i];
    insereProduto(novo);
  }
}
void imprimeUp()
{
    noProduto *cont;
    cont=prim;

    while(cont!=NULL){
    printf("\n[Produto %s - Codigo %s - Quantidade %d] ",cont->produto,cont->codigo,cont->quantidade);
    cont=cont->prox;
    }
}
void imprimeDown()
{
    noProduto *cont;
    cont=ult;

    while(cont!=NULL){
    printf("\n[Produto %s - Codigo %s - Quantidade %d] ",cont->produto,cont->codigo,cont->quantidade);
    cont=cont->ant;
    }
}
void removeProduto(char *codigo)
{
    noProduto *cont,*aux;
    cont=prim;
    aux=prim;
    if(strcmp(prim->codigo,codigo)==0){
        prim=prim->prox;
        prim->prox->ant=NULL;
        free(cont);
        return;
    }
    while(cont!=NULL){
        if(strcmp(cont->codigo,codigo)==0){
        aux->prox=cont->prox;
        cont->prox->ant=aux;
        free(cont);
    return;
    }
        aux=cont;
        cont=cont->prox;
    }
return;
}
void deletaLista(void)
{
    noProduto *cont,*aux;
    cont=prim;
    aux=prim;

    while(cont!=NULL){
    aux=cont;
    cont=cont->prox;
    free(aux);
    }
}
int main()
{
	noProduto *novo;
	char codigo[TAM_CODIGO];

	inserirLista();
    
    int opcao = 1;
	while(opcao != 5)
	{
        printf("\nAtividade 5 de Lab de Estrutura de Dados\n");
    	printf("\nDigite uma das opcoes abaixo\n");
    	printf("1 - para inserir um produto\n");
    	printf("2 - para remover um produto \n");
    	printf("3 - para imprimir em ordem crescente \n");
        printf("4 - para imprimir em ordem decrescente \n");
    	printf("5 - para sair\n");
        printf("Resposta: ");
    	scanf("%d", &opcao);
    	
        getchar();
        switch(opcao)
    	{
    	case 1: 
        	printf("\n>> Insercao de novo contato: \n");
        	novo = (noProduto *) malloc(sizeof(noProduto));
        	novo->ant = NULL;
        	novo->prox = NULL;

        	printf(">>> Produto: ");
        	scanf("%[^\n]s", (novo->produto));
        	setbuf(stdin, NULL);
        	printf(">>> Codigo: ");
        	scanf("%s", (novo->codigo));
        	setbuf(stdin, NULL);
 		    printf(">>> Quantidade: ");
        	scanf("%i", (&novo->quantidade));

        	bool inserido = insereProduto(novo);

        	if(!inserido)
            printf(">>>> Produto ja existente!!\n");
        	else
            printf(">>>> Produto adicionado com sucesso!!\n");

        	getchar();
        	break;
    	
        case 2:
        	printf(">> Remocao de um produto: \n");
        	printf(">>> Codigo: \n");
        	scanf("%s", codigo);

        	removeProduto(codigo);
            getchar();
        	break;
    	
        case 3: 
 	        printf("\n>> Produtos Crescente<<");

        	imprimeUp();
            getchar();
        	break;
    	
        case 4: 
 	        printf("\n>> Produtos Decrescente<<");

        	imprimeDown();
            getchar();
        	break;
    	
        case 5: 
        	printf(">> Saindo do programa...\n");
        	getchar();
        	break;

        default: 
        	printf(">> Opcao invalida; %c\n", opcao);
        	break;
    	}
    	
    	system("cls");
	}
	    deletaLista();
return 0;
}
