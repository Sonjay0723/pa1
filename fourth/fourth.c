#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
  FILE *fp = fopen(argv[1], "r");

  if (!fp) {
    return 1;
  }

  int row1, col1;
  int row2, col2;
  int i, j, k;

  fscanf(fp, "%d\t", &row1);
  fscanf(fp, "%d\n", &col1);

  //printf("row1: %d\n", row1);
  //printf("col1: %d\n", col1);
  int** matrix1 = (int**)malloc(row1*sizeof(int*));

  for (i = 0; i < row1; i++) {
    matrix1[i] = (int*)malloc(col1*sizeof(int));
  }

  for (i = 0; i < row1; i++) {
    for (j = 0; j < col1; j++) {
      fscanf(fp, "%d\t", &matrix1[i][j]);
    }
    fscanf(fp, "\n");
  }

  fscanf(fp, "%d\t", &row2);
  fscanf(fp, "%d\n", &col2);

  //printf("row1: %d\n", row2);
  //printf("col1: %d\n", col2);
  if (col1 != row2) {
    printf("bad-matrices\n");
    return 0;
  }

  int** matrix2 = (int**)malloc(row2*sizeof(int*));

  for (i = 0; i < row2; i++) {
    matrix2[i] = (int*)malloc(col2*sizeof(int));
  }

  for (i = 0; i < row2; i++) {
    for (j = 0; j < col2; j++) {
      fscanf(fp, "%d\t", &matrix2[i][j]);
    }
    fscanf(fp, "\n");
  }

  int** final = (int**)malloc(row1*sizeof(int*));

  for (i = 0; i < row1; i++) {
    final[i] = (int*)malloc(col2*sizeof(int));
  }

  //printf("%s\n", "right before loop");
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      final[i][j] = 0;
      //printf("%s\n", "loop");
      for (k = 0; k < col1; k++) {
        final[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      printf("%d\t", final[i][j]);
    }

    printf("\n");
  }

  free(matrix1);
  free(matrix2);
  free(final);

  fclose(fp);
  return 0;
}
