#include <stdio.h>
#include <stdlib.h>

int interpret(FILE *file) {
  int instructionNumber = 0;
  int tape[30000];
  int instruction = 0;
  unsigned int currChar;

  while ((currChar = fgetc(file) != EOF)) {
    switch (currChar) {
    case '+':
      tape[instruction]++;

    case '-':
      tape[instruction]--;
    case '>':
      instruction++;
    case '<':
      instruction--;
      if (instruction < 0) {
        printf("Error at symbol %d: out of bounds error", instructionNumber);
      }

    case '[':
      printf("TODO");
    case ']':
      printf("TODO");

    case ',':
      printf("TODO");
    case '.':
      printf("TODO");
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Invalid arguments provided, please structure a command as such: "
           "brf*ck <file.txt>");
    return 1;
  }
  FILE *fptr = fopen(argv[1], "r");

  if (fptr == NULL) {
    printf("File could not be found.");
    return 1;
  }
  int currChar;

  while ((currChar = fgetc(fptr)) != EOF) {
    printf("%c", currChar);
  }

  fclose(fptr);
  return 0;
}
