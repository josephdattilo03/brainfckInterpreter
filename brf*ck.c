#include "stack.c"
#include "vector.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void getBracketMap(CharVector *instructions, CharVector *openBrackets,
                   CharVector *closedBrackets) {
  // TODO
}

int interpret(CharVector *instructions) {
  int tape[30000];
  int stackPointer = 0;
  int instructionPointer = 0;
  LinkedStack stack;
  stackInit(&stack);
  while (instructionPointer < instructions->size) {
    switch (vectorGet(instructions, instructionPointer)) {
    case '+':
      tape[stackPointer]++;
    case '-':
      tape[stackPointer]--;
    case '>':
      stackPointer++;
    case '<':
      stackPointer--;
      if (stackPointer < 0) {
        printf("Error at symbol: out of bounds error");
      }
    case '[':
      printf("todo");
    case ']':
      printf("TODO");
    case ',':
      printf("Enter a character:");
      unsigned int newChar = getchar();
      tape[stackPointer] = newChar;
    case '.':
      if (tape[stackPointer] <= 0x10FFFF) {
        putchar(tape[stackPointer]);
      } else {
        printf("current value out of range to output character");
      }
    }
    instructionPointer++;
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
