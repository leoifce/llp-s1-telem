#include <stdio.h>

void somaMatrizes(int tamanho, int A[tamanho][tamanho], int B[tamanho][tamanho], int C[tamanho][tamanho]);

int main() {

 int tamanho;

 printf("Escolha o tamanho das matrizes quadradas: ");
 scanf("%d", &tamanho);

 int A[tamanho][tamanho], B[tamanho][tamanho], C[tamanho][tamanho];

  printf("\nMatriz A\n");
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }
  printf("\nMatriz B\n");
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%d", &B[i][j]);
    }
  }

  somaMatrizes(tamanho, A, B, C);

  printf("\nMatriz C");
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("\nElemento [%d][%d]: %d ", i, j, C[i][j]);
    }
  }
  
  return 0;
}

void somaMatrizes(int tamanho, int A[tamanho][tamanho], int B[tamanho][tamanho], int C[tamanho][tamanho]) {
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}
