#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int cmpstr(char *a, char *b)
{
  while(*a && *b){
    int diff = *a++ - *b++;
    if(diff)
      return 0;
  }
  a++;
  if(!*a && !*b)
    return 1;
  return 0;
}

void main()
{
  char input[100];
  printf("Welcome. Please input a sentence.\nOtherwise input '0' to end the program at any time.\n");
  printf("$ ");
  fgets(input, 100, stdin);
  if(!cmpstr(input, "0")){
    printf("%s\n", input);
    char **tokens = tokenize(input);
    List *head = init_history();
    while(*tokens){
      add_history(head, *tokens);
      tokens++;
    }
    free_tokens(tokens);
    do{
      printf("Type the command '!' followed by the id of a string to pritn it.\n");
      printf("Or, type \"!h\" to view all id's and their strings.\n");
      fgets(input, 100, stdin);
      if(cmpstr(input, "!h"))
	 print_history(head);
      else if(input[0] == '!'){
	 char *restIn = input + 1;
	 int id = atoi(restIn);
	 char *word = get_history(head, id);
	 if(word != NULL)
	   puts(word);
      }
    }
    while(!cmpstr(input, "0"));
    free_history(head);
    }
}
