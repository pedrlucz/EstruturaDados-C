#include <stdio.h>

struct pessoas{
  char nome[30];
  int idade;
};

struct pessoas lista_pessoas[5];

int main(){
  int i;
  
  for (i = 0; i < 5; i++){
  printf("----Cadastro de pessoas----\n");
  printf("Digite o nome da pessoa que deseja cadastrar:");
  //vou usar o scanf pq não precisa ler o nome inteiro da pessoa, se não usava fgets
  scanf("%s", lista_pessoas[i].nome);

  printf("Digite a idade dela:");
  scanf("%d", &lista_pessoas[i].idade); }

  for (int pass = 0; pass < 5 - 1; pass++){
    for (int j = 0; j < 5 - 1; j++){
      // pra se for necessário
      if (lista_pessoas[j].idade < lista_pessoas[j + 1].idade){
        struct pessoas temp = lista_pessoas[j];
        lista_pessoas[j] = lista_pessoas[j + 1];
        lista_pessoas[j + 1] = temp;
      }
    }
  }
  
  int ia;
  for (ia = 0; ia < 5; ia++){

  printf("lendo os dados da struct\n");
  printf("Nome: %s\n", lista_pessoas[ia].nome);
  printf("Idade: %d\n", lista_pessoas[ia].idade); }

  return 0;
}
