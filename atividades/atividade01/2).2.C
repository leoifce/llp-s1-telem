#include <stdio.h>

int main() {
  int n = 3;
  int matrizA[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrizB[3][3] = { {0, 1, 0}, {1, 0, 1}, {0, 1, 1}};
  
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
     printf("%d ", matrizA[i][j]+matrizB[i][j]);
    }
   printf("\n");
  }
  
  return 0;
}
