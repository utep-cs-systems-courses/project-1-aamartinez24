#include "history.h"

List *init_history()
{
  List *head = (List*) malloc(sizeof(List));
  head->root = 0;
  return head;
}

void add_history(List *list, char *str)
{
  Item *newItem = (Item*) malloc(sizeof(Item));
  if(list->root == 0){
    newItem->id = 1;
    list->root = newItem;
  }
  else{
    Item *currItem = list->root;
    while(currItem->next != 0)
      currItem = currItem->next;
    newItem->id = currItem->id + 1;
    currItem->next = newItem;
  }
  newItem->str = str;
  newItem->next = 0;
}

char *get_history(List *list, int id)
{
  Item *currItem = list->root;
  while(currItem != 0){
    if(currItem->id == id)
      return currItem->str;
    currItem = currItem->next;
  }
  printf("id not found\n");
  return 0;
}

void print_history(List *list)
{
  Item *currItem = list->root;
  while(currItem != 0){
    printf("id: %d\n", currItem->id);
    printf("string: ");
    puts(currItem->str);
    currItem = currItem->next;
  }
}

void free_history(List *list)
{
  Item *currItem = list->root;
  while(currItem != 0){
    free(currItem);
    currItem = currItem->next;
  }
  free(list);
}
