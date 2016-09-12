// line-getter4E.c
// ENCM 339 Fall 2015 Lab 4 Exercise E

#include <stdio.h>
#include <string.h>

#define QUIT_LETTER 'q'

// Again, in a practical program, this is a ridiculously small size
// for an array that is supposed to hold a line of text. But it's
// convenient for testing purposes.
#define LINE_ARRAY_SIZE 8

int eat_til_newline(FILE *stream);
// REQUIRES: stream is open for input.
// PROMISES: Characters are read from stream and discarded until either a
//   '\n' has been read or an input error has occurred.
//   Return value is 0 if '\n' is read, and EOF for an error.

int get_a_line(char *s, int size, FILE *stream);
// Does what fgets does, using repeated calls to fgetc, but
// provides a more useful return value than fgets does.
//
// REQUIRES
//   size > 1.
//   s points to the start of an array of at least size bytes.
//   stream is open for input.
// PROMISES
//   Return value is EOF if input error occurred.
//   Otherwise, return value gives the index of the '\0' that
//   terminates the string in the array.

void reverse(char *s);
//REQUIRES
//  s points to a valid c-string
//PROMISES
//  The c-string that s points to will be reversed in place
//  up to but not including the first occurence of '\0'l

int main(void)
{
  char line[LINE_ARRAY_SIZE];
  int input_error = 0, len;

   while (1) {
    printf("Please enter a line of text. To quit, start it with %c.\n", QUIT_LETTER);
    len = get_a_line(line, LINE_ARRAY_SIZE, stdin);
    if (len == EOF) {
      input_error = 1;
      break;
    }
    if (line[0] == QUIT_LETTER)
      break;
    if (line[len-1] == '\n') {
      line[len-1] = '\0';
      printf("The line, newline removed, was \"%s\".", line);
      reverse(line);
      printf("  In reverse, that is \"%s\".\n", line);
    } else if (len == LINE_ARRAY_SIZE-1) {
      eat_til_newline(stdin);
      fputs("Input line ignored because it was too long!\n", stdout);
    } else {
      input_error = 1;
      break;
    }
  } // while (1)

  fputs("\nReason for quitting: ", stdout);
  if (input_error)
    fputs("unexpected input error.\n", stdout);
  else
    printf("found %c at beginning of line.\n", QUIT_LETTER);

  return 0;
}

int eat_til_newline(FILE * stream)
{
  int c;
  do {
    c = fgetc(stream);
  } while (c != EOF && c != '\n');

  // Return EOF if c == EOF, otherwise return 0.
  return (c == EOF) ? EOF : 0;
}

int get_a_line(char *s, int size, FILE *stream)
{
    int c, readChar = 0;
    while (readChar < size-1) {
        c = fgetc(stream);
        if (c == EOF) {
            return EOF;
        } else {
            s[readChar] = c;
            readChar++;
            if (c == '\n')
                break;
        }
    }
    s[readChar] = '\0';
    return readChar;
}

void reverse(char *s)
{
  int j = 0, i;
  while (s[j] != '\0')
      j++;
  for (i = 0, j -= 1; i < j; i++, j--) {
      char storage = s[i];
      s[i] = s[j];
      s[j] = storage;
  }
}
