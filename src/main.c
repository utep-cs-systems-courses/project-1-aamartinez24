#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int cmpstr(char *a, char *b)/*Checks if two strings are the same */
{
  while(*a && *b){
    int diff = *a++ - *b++;
    if(diff)                /* Strings are different */
      return 0;
  }
  a++;
  if(!*a && !*b)            /* Strings are the same */
    return 1;
  return 0;
}

void main()
{
  char input[100];
  printf("Welcome. Please input a sentence.\nOtherwise input '0' to end the program at any time.\n");
  printf("$ ");
  fgets(input, 100, stdin);
  if(!cmpstr(input, "0")){   /* Did not exit program */
    printf("%s\n", input);
    char **tokens = tokenize(input);  /* Tokenize the string inputted */
    List *head = init_history();      /* Initalize a List */
    while(*tokens){
      add_history(head, *tokens);     /* Add each string to a Node of a List */
      tokens++;
    }
    free_tokens(tokens);
    do{
      printf("Type the command '!' followed by the id of a string to pritn it.\n");
      printf("Or, type \"!h\" to view all id's and their strings.\n");
      fgets(input, 100, stdin);       /* Command inputs */
      if(cmpstr(input, "!h"))         /* Prints all the words with their ids */
	 print_history(head);
      else if(input[0] == '!'){
	char *restIn = input + 1;     /* Rest of command inputs that describes id number */
	int id = atoi(restIn);       /* Converts string input to an integer */
	 char *word = get_history(head, id);
	 if(word != NULL)             /* Id was found, print word */
	   puts(word);
      }
    }
    while(!cmpstr(input, "0"));       /* Repeate until user decides to exit */
    free_history(head);
    }
}
