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
  int state = 0;
  while(*str){
    if(state == 0 && non_space_char(*str)){
      state = 1;
      ++words;
    }
    else if(state == 1 && space_char(*str))
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
    p[i] = inStr[i];
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
    b = word_start(str);
    e = word_terminator(b);
    if(e != 0)
      len = e - b;
    else{
      int j = 0;
      while(*str){
	j++;
	str++;
      }
      len = j;
    }
    str = b;
    str+=len+1;
    tokens[i] = copy_str(b, len);
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens)
{
  while(*tokens){
    puts(*tokens);
    tokens++;
  }
  return;
}
  
void free_tokens(char **tokens)
{
  while(*tokens){
    free(*tokens);
    tokens++;
  }
  return;
}
