#include <stdio.h>

int somatorio(int n);

int main(void) {

  int n;
  
  printf("Digite um numero inteiro para ver o seu somatorio ate zero: ");
  scanf("%d", &n);
  printf("O somatorio e: %d", somatorio(n));
  
  return 0;
}

int somatorio(int n){

  if (n > 0){
    return n + somatorio(n-1);
  }else{
   return 0; 
   }
}
