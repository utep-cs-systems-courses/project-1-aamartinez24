int space_char(char c)
{
  if(c == ' ' || c == '\t')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  if(c != ' ' && c != '\t')
    return 1;
  return 0;
}

char word_start(char *str)
{
  while(*str){
    if(non_space_char(*str))
      return *str;
    *str++;
  }
  return 0;
}

char *word_terminator(char *word)
{
  char *end = word;
  while(*end){
    if(space_char(*end))
      return *end;
    *end++;
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
    *str++;
  }
  return words;
}
