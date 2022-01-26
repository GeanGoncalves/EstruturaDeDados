//Gean Carlos Gonçalves Martins
//2020021262

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef enum{false, true} bool;

typedef struct no{
int valor;
struct no* prox;
}noResis;

noResis *pilha[7];
int valorResis[7]={2,3,5,10,20,50,100};
int qntd[7];

void inicializaPilha();
void abastecePilha(int quant, int v);
void imprimeTudo();
void imprimeSoma();
bool resisDisponivel(int valor);
bool entrega(int valor);

void inicializaPilha(){
    int i;
    
    for(i=0;i<7;i++){
    pilha[i] = NULL;
    }
}

void abastecePilha(int quant, int v){
    int pos,i=0;
    noResis *novo;
    
    switch(v){
    case 2:
    pos = 0;
    break;
    
    case 3:
    pos = 1;
    break;
    
    case 5:
    pos = 2;
    break;
    
    case 10:
    pos = 3;
    break;
    
    case 20:
    pos = 4;
    break;
    
    case 50:
    pos = 5;
    break;
    
    case 100:
    pos = 6;
    break;
    
    default:
    printf("Valor de resistencia invalido!");
    }

    while(i<quant){
    novo = (noResis *)malloc(sizeof(noResis));
    novo->valor = v;
    novo->prox = pilha[pos];
    pilha[pos] = novo;
    i++;
    qntd[pos]++;
    }
}

void imprimeTudo(){
    noResis *atual;
    int i=0,soma = 0;
    
    for(i=0;i<7;i++){
    atual = pilha[i];
    while(atual!=NULL){
    soma = soma + atual->valor;
    atual = atual->prox;
    }

    printf("Valor de resistencia: %d Ohms, Quantidade: %d \n",valorResis[i],qntd[i]);
    }
    printf("\n\n[Disponivel: %d Ohms]\n\n",soma);
}

void imprimeSoma(){
    noResis *atual;
    int i=0,soma = 0,qd;
    
    for(i=0;i<7;i++){
    atual = pilha[i];
    while(atual!=NULL){
    soma = soma + atual->valor;
    atual = atual->prox;
    }
    qd = valorResis[i]*qntd[i];
    
    printf("Valor de resistencia: %d Ohms, quantidade disponivel em: %d Ohms \n",valorResis[i],qd);
    }
    printf("\n");
}

bool resisDisponivel(int valor){
    int i;
    noResis *atual;
    
    for(i=6;i>=0;i--){
    atual = pilha[i];
    while((atual!=NULL)&&(valor/atual->valor >=1)){
    valor = valor - atual->valor;
    atual = atual->prox;
    
    if(valor == 1){
    valor = valor + atual->valor;
    break;}
    }
    }

    if(valor == 0)
    return true;
    else
    return false;
    }

bool entrega(int valor){
    int i;
    noResis *atual;
    
    if(resisDisponivel(valor)){
    for(i=6;i>=0;i--){
    while((atual!=NULL)&&(valor / valorResis[i] >=1)){
    valor = valor - pilha[i]->valor;
    atual = pilha[i];
    
    if(valor == 1){
    valor = valor + pilha[i]->valor;
    break;
    }
    
    pilha[i] = atual->prox;
    free(atual);
    qntd[i]--;
    }
    }
    
    return true;
    }
    else
    return false;
}

int main(int argc, char ** argv){
    int i;
    inicializaPilha();
    abastecePilha(55, 2);
    abastecePilha(42, 3);
    abastecePilha(61, 5);
    abastecePilha(28, 10);
    abastecePilha(35, 20);
    abastecePilha(64, 50);
    abastecePilha(14, 100);
    
    printf("\n[LAB 7 DE ESTRUTURA DE DADOS]\n");
    printf("Valor Inicial do Almoxarifado \n");
    printf("====================================\n");
    imprimeTudo();
    imprimeSoma();

    int pedidos[4] = {43,75,123,256};
    for(i=0;i<4;i++){
    printf("______________________________\n");
    printf("Pedido de = %d ohms\n",pedidos[i]);
    printf("Verificando almoxarifado: ");
     
    if (entrega(pedidos[i])){
    printf("Disponivel!\n");
    imprimeTudo();
    imprimeSoma();
    }
     
    else{
    printf("Indisponivel!\n");
    }
    }

    printf("Valor Final do Almoxarifado \n");
    printf("====================================\n");
    imprimeTudo();
    imprimeSoma();
 return 0;
}
