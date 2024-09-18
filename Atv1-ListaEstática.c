//Gean Carlos Gonçalves Martins
//2020021262

#include <stdio.h>
#include <string.h>
#define MAX 20

typedef enum{false, true } bool;
char ListaItens[20][20];
char op, Item[20];
int x=0;

bool InsereItens(Item){
    int i=x;
    if (x>MAX){
    return false;
}

    else{
    while((i>0)&&(strcmp(ListaItens[i-1],Item)>0)){
    strcpy(ListaItens[i],ListaItens[i-1]);
    i--;
}
    strcpy(ListaItens[i],Item);
    x++;
    return true;

   }
 }

void MostraLista(){
    for(int i=0;i<x;i++){
    printf("Posicao: %d Item: %s \n",i,ListaItens[i]);
}
}

 bool RemoveItem(Item){
    int i=0;
    while((i<x)&&(strcmp(ListaItens[i],Item)<0)){
    i++;
    }
    if ((i<x)&&(strcmp(ListaItens[i],Item)== 0)){
    while(i<x-1){
    strcpy(ListaItens[i],ListaItens[i+1]);
    i++;
    }
    x--;
    printf("Item foi removido\n");
    return true;
    }else{
    return false;}
 }

 bool BuscaItem(Item){
   for(int i=0;i<x;i++){
   if (strcmp(ListaItens[i],Item)== 0){
   return true;
 }
 }
return false;
 }

int main (int argc, char *argv){

    while('op' != 's'){
    printf("------------------\n i: Inserir Item\n r: Remover Item\n b: Buscar  Item\n m: Mostrar Lista\n s: Sair \n");
    printf("------------------\n");
    scanf("%s",& op);


 switch(op){
    case 'i' :
    printf("Digite o item a ser inserido:\n");
    setbuf(stdin,NULL);
    gets(Item);
    if(BuscaItem(Item)==true){
    printf("Item ja consta na lista\n");
    }
    else if (InsereItens(Item)==true)
    {printf("Item inserido\n");}
    else{printf("Limite atingido\n");}
    break;

    case 'r' :
    printf("Digite o item a ser retirado:\n");
    setbuf(stdin,NULL);
    gets(Item);
    if(BuscaItem(Item)==true)
    {RemoveItem(Item);
    }else{
    printf("Item nao identificado na lista\n");
}
    break;


    case 'b' :
    printf("Digite o Item:\n");
    setbuf(stdin,NULL);
    gets(Item);
    if(BuscaItem(Item)==true){
    printf("Item identificado\n");}
    else{printf("Item nao identificado na lista\n");  }
    break;

    case 'm':
    MostraLista();
    break;

    case 's':
    return 0;
}
    }
return 0;
}
