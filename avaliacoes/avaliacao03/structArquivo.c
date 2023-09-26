#include <stdio.h>

struct Cadastro {
    char nome[50];
    int idade;
};

int main(){

 struct Cadastro pessoa1;

 printf("Digite o nome: ");
 scanf("%s", &pessoa1.nome);
 printf("Digite a idade: ");
 scanf("%d", &pessoa1.idade);

 FILE *arquivo = fopen("cadastro.txt", "w");
  fprintf(arquivo, "Nome: %s\nIdade: %d", pessoa1.nome, pessoa1.idade);
 fclose(arquivo);
  
}
