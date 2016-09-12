// structs5C.c
// ENCM 339 Fall 2015 Lab 5 Exercise C

#include <stdio.h>

#define MAX_NAME_LEN 7

struct planet {
  char name[MAX_NAME_LEN + 1];
  double km_from_sun;
};

struct planet_plus {
  struct planet pl;
  int moon_count;
};

void copy(struct planet *dest, const struct planet *src)
{
  char *p = dest->name;
  const char *q = src->name;
  while (1) {
    *p = *q;
    if (*q == '\0')
      break;
    p++;
    q++;
  }

  // point one
 
  dest->km_from_sun = src->km_from_sun;
}

void print_moon_count(const struct planet_plus *p)
{
  // Modify this printf call so that it displays the name of the
  // planet as well has the moon count.
  printf("The planet has %d moon(s).\n", p->moon_count);
  printf("The planet's name is %s.\n", p->pl.name);
}

int main(void)
{
  struct planet aa = {"Jupiter", 779e6}, bb = {"Mars", 228e6};
  struct planet_plus cc = { {"Neptune", 4.495e9}, 14 };
  copy(&aa, &bb);
  printf("%s is, on average, %g million km from the sun.\n",
	 aa.name, aa.km_from_sun / 1e6);
  print_moon_count(&cc);
  return 0;
}
