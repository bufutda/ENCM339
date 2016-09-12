// ENCM 339 Fall 2015 Lab 3 Exercise E

#include <stdio.h>

int main(void)
{
  char buffer[80];   // enough space for a string of length <= 79

  // THIS IS A GOOD WAY TO LEARN SOMETHING ABOUT C STRINGS, BUT IT'S
  // NOT A GOOD EXAMPLE OF READABLE OR PRACTICAL CODE!

  // Put characters into the string using ASCII codes.
  buffer[0] = 64;
  buffer[1] = 35;
  buffer[2] = 36;
  buffer[3] = 37;
  buffer[4] = 33;
  buffer[5] = 32;
  buffer[6] = 51;
  buffer[7] = 51;
  buffer[8] = 57;
  buffer[9] = 32;
  buffer[10] = 105;
  buffer[11] = 115;
  buffer[12] = 110;
  buffer[13] = 39;
  buffer[14] = 116;
  buffer[15] = 32;
  buffer[16] = 97;
  buffer[17] = 108;
  buffer[18] = 119;
  buffer[19] = 97;
  buffer[20] = 121;
  buffer[21] = 115;
  buffer[22] = 32;
  buffer[23] = 102;
  buffer[24] = 117;
  buffer[25] = 110;
  buffer[26] = 33;

  // Put the end-of-string character at the end of the string.
  buffer[27] = 0;

  printf("The string in buffer is \"%s\"\n", buffer);
  return 0;
}
