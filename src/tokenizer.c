#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if(c != ' ' && c != '\t' && c != '\n')
    return 1;
  return 0;
}

char *word_start(char *str)
{
  while(*str){
    if(non_space_char(*str))
      return str;
    str++;
  }
  return 0;
}

char *word_terminator(char *word)
{
  while(*word){
    if(space_char(*word))
      return word;
    word++;
  }
  return;
}
  
int count_words(char *str)
{
  int words = 0;
  int state = 0;        /* Determines if the pointer is inside a word(1) or outside(0) */
  while(*str){
    if(state == 0 && non_space_char(*str)){ /* Points to a new word */
      state = 1;
      ++words;
    }
    else if(state == 1 && space_char(*str)) /* Exits word */
      state = 0;
    str++;
  }
  return words;
}

char *copy_str(char *inStr, short len)
{
  char *p = malloc(sizeof(char) * len + 1);
  int i;
  for(i = 0; i < len; i++)
    p[i] = inStr[i];        /* Copies each character to the new allocated space */
  p[i] = '\0';
  return p;
}

char **tokenize(char *str)
{
  int nwords = count_words(str);
  char **tokens = malloc(sizeof(char*) * nwords + 1);
  char *b, *e;
  short len;
  int i;
  for(i = 0; i < nwords; i++){
    b = word_start(str);    /* First character of a word */
    e = word_terminator(b); /* Space after the end character of a word */
    if(e != 0)
      len = e - b;          /* Length of a word */
    else{                   /* e points to the end of the whole string (NULL) */
      int j = 0;
      while(*str){          /* Get length by going thru the word with an integer */
	j++;
	str++;
      }
      len = j;
    }
    str = b;
    str+=len+1;             /* Automatically point to the beginning of the next word */
    tokens[i] = copy_str(b, len);
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens)
{
  while(*tokens){
    puts(*tokens);          /* Prints the whole string of each pointer */
    tokens++;
  }
  return;
}
  
void free_tokens(char **tokens)
{
  while(*tokens){
    free(*tokens);          /* Deallocates the all the memory that was allocated before */
    tokens++;
  }
  return;
}
