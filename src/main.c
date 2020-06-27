#include <stdio.h>

void main()
{
  char input[100];
  printf("$ ");
  fgets(input, 100, stdin);
  printf("%s\n", input);
}
