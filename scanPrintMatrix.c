#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void scanMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
  printf("Enter matrix elements:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
  printf("Matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rows, cols;
  int matrix[MAX_ROWS][MAX_COLS];

  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  scanMatrix(matrix, rows, cols);
  printMatrix(matrix, rows, cols);

  return 0;
}
