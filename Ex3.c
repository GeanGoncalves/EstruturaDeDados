//Gean Carlos Gonçalves Martins
//2020021262


//QUESTÃO 1 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int x, i;
  printf("\tQuestao 1");
  scanf("%d", &x);

  int *vet = (int *) malloc(x * sizeof(int));
  for(i = 0; i < x; i++)
  
  {
  vet[i] = rand() % 100;
  printf("[%d] = %d\n", i, vet[i]);
  }
  printf("\n");
  free(vet);
  
  return 0;
}


//QUESTÃO 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int l, c, A[20][10], B[20][10], C[20][10];

    srand(time(NULL));

    for(l = 0; l < 20; l++){
    for(c = 0; c < 10; c++){
            
    A[l][c] = rand() % 100; 
    B[l][c] = rand() % 100; 
    C[l][c] = A[l][c] + B[l][c]; 
    }
    }
    printf("\n\t       Questao 2\n");

    printf("\n\t       MATRIZ A\n");
    for(l = 0; l < 20; l++){
    for(c = 0; c < 10; c++)
    printf("%3d ", A[l][c]);
    printf("\n");
    }

    printf("\n\t       MATRIZ B\n");
    for(l = 0; l < 20; l++){
    for(c = 0; c < 10; c++)
    printf("%3d ", B[l][c]);
    printf("\n");
    }

    printf("\n\t       MATRIZ C\n");
    for(l = 0; l < 20; l++){
    for(c = 0; c < 10; c++)
    printf("%3d ", C[l][c]);
    printf("\n");
    }

return 0;
}

//QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char livro[30], autor[30], editora[30], classificacao[30];
  int ano;
} st_livros;

int main(int argc, char *argv[]){
  int ano, i;
  char l[30], a[30], e[30], c[30];
    
    st_livros *vet = (st_livros *) malloc(10* sizeof(st_livros));
    for(i = 0; i < 10; i++){

    printf("\tQuestao 3\n");
    printf("Informe o nome do livro: ");
    gets(l);

    printf("Informe o nome do(a) autor(a) do livro: ");
    gets(a);

    printf("Informe a editora do livro: ");
    gets(e);

    printf("Informe a classificacao do livro: ");
    gets(c);
    fflush(stdin);

    printf("Digite o ano: ");
    scanf("%d", &ano);
    fflush(stdin);

    strcpy(vet[i].livro, l);
    strcpy(vet[i].autor, a);
    strcpy(vet[i].editora, e);
    strcpy(vet[i].classificacao, c);
    vet[i].ano = ano;
  }
    for(i = 0; i < 10; i++){
    printf("\n%s - %s - %s - %s - %d\n", vet[i].livro, vet[i].autor, vet[i].editora, vet[i].classificacao, vet[i].ano);
  }
    free(vet);
  return 0;
}
