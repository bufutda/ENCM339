// charIO4D.c
// ENCM 339 Fall 2015 Lab 4 Exercise D

#include <stdio.h>
#include <ctype.h>

#define QUIT_LETTER 'q'

int main(void)
{
  int c, line_length, digits;

  // Each pass through the outer loop reads a line of input.
  while (1) {
    printf("\nEnter a line of text. (To quit, start the line with %c.)\n",
	   QUIT_LETTER);
    c = fgetc(stdin);
    if (c == EOF || c == QUIT_LETTER)
      break;			// Leave outer loop.

    line_length = 0;
    digits = 0;
    printf("Changing uppercase to lowercase ...\n");

    // Inner loop reads chars until '\n' or EOF is found.
    while (c != '\n' && c != EOF) {
      line_length++;
      fputc(tolower(c), stdout);
      c = fgetc(stdin);
      if (c > 47 && c < 59)
        digits++;
    }
    fputc('\n', stdout);
    printf("Length of line, not counting '\\n', was %d.\n", line_length);
    printf("%d of the characters in the line were digits.\n", digits);
  }

  printf("Bye!\n");
  return 0;
}
