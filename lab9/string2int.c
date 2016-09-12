// string2int.c
// ENCM 339 Fall 2015 Lab 9 Exercise B, Part 2

#include <stdio.h>
#include <ctype.h>

int from_string(const char *s, const char **endptr)
{
  // Advance to '\0' or first non-whitespace char.
  int i = 0;
  while (s[i] != '\0' && isspace(s[i]))
    i++;
  if (s[i] == '\0') {
    *endptr = NULL;
    return 0;
  }
  
  // Is there a sign?
  int is_negative = 0;
  if (s[i] == '-') {
    i++;
    is_negative = 1;
  }
  else if (s[i] == '+')
    i++;

  // We need at least one digit.
  if (!isdigit(s[i])) {
    *endptr = NULL;
    return 0;
  }

  // Attention: This algorithm is okay for this lab exercise but MUST
  // NOT be used in production code, because it does not guard against
  // overflow, which will happen if the number being read from the
  // string is out of the range of the int type.
  int result = s[i] - '0';
  i++;
  while (isdigit(s[i])) {
    result = 10 * result + s[i] - '0';
    i++;
  }
  *endptr = &s[i];

  // point one

  return is_negative ? -result : result;
}
   
void report(int fsrv, const char *p)
{
  printf("\nReturn value from from_string was %d.\n", fsrv);
  if (p != NULL)
    printf("p points to \"%s\".\n", p);
  else
    printf("p is a null pointer.\n");
}

int main(void)
{
  const char *p = NULL;
  int first, second, third;

  first = from_string("31 -128 hello", &p);
  report(first, p);
 
  second = from_string(p, &p);
  report(second, p);

  third = from_string(p, &p);
  report(third, p);

  return 0;
}
