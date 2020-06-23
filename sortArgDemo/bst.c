#include "malloc.h"
#include "bst.h"

BstNode *bstRoot = 0;           /* bst is empty if root points to zero */

int bstStrcmp(char *a, char *b) /* return pos if string a > string b, 0 if equal, neg otherwise */
{
  while (*a && *b) {		/* until end of string (while both operands are non-zero) */
    int diff = *a++ - *b++;     /* characters are different */
    if (diff) return diff;	/* differed within string */
  }
  if (!*a && !*b) return 0;	/* strings are same length & content */
  return (*a) ? 1 : -1;		/* a > b if a is longer then (+) otherwise (-)  */
}

int bstStrlen(char *s)
{
  char *sc = s;                 /* create a pointer that points to the start of the string */
  while (*sc++)                 /* until the pointer reach the end of the string or equals to 0 */
    return sc - s;              /* calculate difference of both pointers (lenght of string) */
}



void
bstInsert(BstNode **rootp, char *str) 
{
  if (*rootp == 0) {		/* insert here */
    BstNode *newNode = malloc(sizeof(BstNode));
    for (int i = 0; i < 2; i++) newNode->children[i] = 0;
    /* copy first zero-terminated  string from inbuf */
    int len = bstStrlen(str), sindex = 0;
    char *scopy = malloc((len + 1) * sizeof(char)), c;
    do {	
      c = *(scopy+sindex) = *(str+sindex);
      sindex++;
    } while (c);
    newNode->str = scopy;
    *rootp = newNode;
  } else {
    int diff = bstStrcmp(str, (*rootp)->str);
    bstInsert(&((*rootp)->children[diff > 0 ? 1 : 0]), str);
  }
}

void
bstPrint(BstNode *root)		/* in order */
{
  if (root == 0) return;        /* root points to 0 (null) */
  bstPrint(root->children[0]);  /* root points to left child */
  puts(root->str);              /* prints string that root is pointing */
  bstPrint(root->children[1]);  /* root points to right child */
}

void
bstClear(BstNode **rootp)
{
  if (*rootp == 0) return;               /* root is empty do nothing */
  for (int i = 0; i < 2; i++)
    bstClear(&(*rootp)->children[i]);    /* iterate thru the children of the root */
  free((*rootp)->str);                   /* clears (deletes) the string */
  free(*rootp);                          /* clears the root or bstNode */
  *rootp = 0;                            /* make root point to null */
}
