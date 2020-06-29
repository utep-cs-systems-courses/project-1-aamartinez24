#include "history.h"

List *init_history()
{
  List *head = (List*) malloc(sizeof(List));
  head->root = 0;                /* List is empty and Node points to zero */
  return head;
}

void add_history(List *list, char *str)
{
  Item *newItem = (Item*) malloc(sizeof(Item));
  if(list->root == 0){           /* Insert first Node which will become the head of the list */
    newItem->id = 1;             /* Id is 1 since is the first Node */
    list->root = newItem;
  }
  else{
    Item *currItem = list->root; /* Pointer that will help iterate thru the list */
    while(currItem->next != 0)
      currItem = currItem->next;
    newItem->id = currItem->id + 1; /* Set new id of new Node to be +1 to the previous Node id */
    currItem->next = newItem;    /* Set next Node to be the new Node */
  }
  newItem->str = str;            /* Insert String to new Node */
  newItem->next = 0;             /* Set next Node to 0 */
}

char *get_history(List *list, int id)
{
  Item *currItem = list->root;
  while(currItem != 0){
    if(currItem->id == id)       /* id found */
      return currItem->str;
    currItem = currItem->next;
  }
  printf("id not found\n");
  return 0;
}

void print_history(List *list)
{
  Item *currItem = list->root;
  while(currItem != 0){         /* Prints the content of each Node */
    printf("id: %d\n", currItem->id);
    printf("string: ");
    puts(currItem->str);
    currItem = currItem->next;
  }
}

void free_history(List *list)
{
  Item *currItem = list->root;
  while(currItem != 0){        /* Deallocates memory of each Node */
    free(currItem);
    currItem = currItem->next;
  }
  free(list);
}
