#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) {
  int i;
  int j;

  for (i = 1; i < argc; i++) {
    int wordLength = strlen(argv[i]);

    for (j = 0; j < wordLength; j++) {
      if (argv[i][j] == 'a' || argv[i][j] == 'A') {
        printf("%c", argv[i][j]);
      }
      if (argv[i][j] == 'e' || argv[i][j] == 'E') {
        printf("%c", argv[i][j]);
      }
      if (argv[i][j] == 'i' || argv[i][j] == 'I') {
        printf("%c", argv[i][j]);
      }
      if (argv[i][j] == 'o' || argv[i][j] == 'O') {
        printf("%c", argv[i][j]);
      }
      if (argv[i][j] == 'u' || argv[i][j] == 'U') {
        printf("%c", argv[i][j]);
      }
    }
  }
  printf("\n");
  return 0;
}
