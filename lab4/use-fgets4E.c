// use-fgets4E.c
// ENCM 339 Fall 2015 Lab 4 Exercise E

#include <stdio.h>

#define QUIT_LETTER 'q'

// In a practical program, this is a ridiculously small size for an array to
// hold a line of text. But it's convenient for this simple demonstration
// program.
#define LINE_ARRAY_SIZE 8

int main(void)
{
  char line[LINE_ARRAY_SIZE];
  char *fgets_rv;

  while (1) {
    printf("Please enter a line of text. To quit, start it with %c.\n",
	  QUIT_LETTER);
    fgets_rv = fgets(line, LINE_ARRAY_SIZE, stdin);
    if (fgets_rv == NULL || line[0] == QUIT_LETTER)
      break;
    printf("\nInput line was \"%s\"\n", line);
  }
  fputs("\nReason for quitting: ", stdout);
  if (fgets_rv == NULL)
    fputs("unexpected input error.\n", stdout);
  else
    printf("found %c at beginning of line.\n", QUIT_LETTER);

  return 0;
}
