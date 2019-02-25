#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
  int amount;

  FILE *fp = fopen(argv[1], "r");

  if (!fp) {
    return 1;
  }

  fscanf(fp, "%d\n", &amount);
  int numbers[amount];
  //printf("%d\n", amount);
  int i, j;
  for (i = 0; i < amount; i++) {
    fscanf(fp, "%d\t", &numbers[i]);
  }
  /*printf("hi\n");
  for (i = 0; i < amount; i++) {
    printf("%d\t", numbers[i]);
  }*/

  int evens = 0;
  int odds = 0;

  for (i = 0; i < amount; i++) {
    if (numbers[i]%2 == 0) {
      evens++;
    }
    else {
      odds++;
    }
  }

  int evenNum[evens];
  int oddNum[odds];

  evens = 0;
  odds = 0;

  for (i = 0; i < amount; i++) {
    if (numbers[i]%2 == 0) {
      evenNum[evens] = numbers[i];
      evens++;
    }
    else {
      oddNum[odds] = numbers[i];
      odds++;
    }
  }

  for (i = 0; i < evens - 1; i++) {
    int min = evenNum[i];
    int index = i;

    for (j = i + 1; j < evens; j++) {
      if (evenNum[j] < min) {
        min = evenNum[j];
        index = j;
      }
    }

    if (i != index) {
      int temp = evenNum[i];
      evenNum[i] = evenNum[index];
      evenNum[index] = temp;
    }
  }

  for (i = 0; i < odds - 1; i++) {
    int max = oddNum[i];
    int index = i;

    for (j = i + 1; j < odds; j++) {
      if (oddNum[j] > max) {
        max = evenNum[j];
        index = j;
      }
    }

    if (i != index) {
      int temp = oddNum[i];
      oddNum[i] = oddNum[index];
      oddNum[index] = temp;
    }
  }

  for (i = 0; i < evens; i++) {
    printf("%d\t", evenNum[i]);
  }

  for (i = 0; i < odds; i++) {
    printf("%d\t", oddNum[i]);
  }

  printf("\n");
  fclose(fp);
  return 0;
}
