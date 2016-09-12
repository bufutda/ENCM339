// ENCM 339 Fall 2015 Lab 3 Exercise F

#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s);
// Duplicates the library strlen function.
// REQUIRES
//   s points to the first char in a C string.
// PROMISES
//   Return value is the number of characters in the string up to but
//   not including the terminating '\0'.

char *my_strcat(char *dest, const char *src);
// Duplicates the library strcat function.
// REQUIRES
//   dest and src to point to the beginnings of C strings.
//   dest points to the beginning of an array with at least this
//   many chars: strlen(dest) + strlen(src) + 1.
// PROMISES
//   C string pointed to dest is modified by appending all the characters
//   from the src string.
//   Return value is the address of the first char in the dest string.


int main(void)
{
  // Use strlen a few times.
  printf("strlen(\"\") returns %zu.\n", my_strlen(""));
  printf("strlen(\"A\") returns %zu.\n", my_strlen("A"));
  printf("strlen(\"ABCDE\") returns %zu.\n\n", my_strlen("ABCDE"));

  // Now demonstrate a few uses of strcat.
  // Start with an empty string, followed by junk characters.
  char s[16] = {'\0', 'X', 'X', 'X', 'X', 'X', 'X', 'X',
                'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'};
  char *p;
  p = my_strcat(s, "");            // Append empty string to empty string.
  printf("First strcat result:  \"%s\"\n", p);
  p = my_strcat(s, "E");           // Append a string of length 1.
  printf("Second strcat result: \"%s\"\n", p);
  p = my_strcat(s, "NCM");         // Append a longer string.
  printf("Third strcat result:  \"%s\"\n", p);
  p = my_strcat(s, " 339!");       // Append another longer string.
  printf("Fourth strcat result: \"%s\"\n", p);
  p = my_strcat(s, "");            // Append another empty string.
  printf("Fifth strcat result:  \"%s\"\n", p);

  return 0;
}

size_t my_strlen(const char *s)
{
  size_t len = 0;
  while (s[len] != '\0')
    len++;
  return len;
}

char *my_strcat(char *dest, const char *src)
{
  size_t len = strlen(dest);
  int index = 0;
  while (src[index] != '\0') {
    dest[len+index] = src[index];
    index++;
  }
  dest[len+index] = '\0';
  return dest;
}
