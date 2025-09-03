/*

VULNERABLE

Note: Did not know much on the Heap at this time, but I get a crash
      running: cat a.out | ./a.out

      I think this occurs since I am not freeing the heap?

Write a program that prints the distinct words in its input sorted
into decreasing order of frequency of occurrence. Precede each word
by it's count.

A: So for example:

  The: 8
  ate: 4
  dog: 2

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "getword.h"

#define MAXWORD 100

struct tnode {
  char *word;           /* points to the string/char array */
  int count;            /* number of occurrences */
  struct tnode *left;   /* left child */
  struct tnode *right;  /* right child */
};

struct tnode *addtree(struct tnode *, char *);
int treeassign(struct tnode *, const char *[], int);
void sorted_print(const char *[], int);

int main()
{
  int count;
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);

  /* get the nodes in order */
  int list = sizeof(root)+1;
  const char *ptr_list[list*2];

  count = treeassign(root, ptr_list, list);

  sorted_print(ptr_list, count);

  return 0;
}

/* index_array: index where a char appears in the char array */
int index_array(const char *str, int c)
{
  int i, j = 0;
  int startc = 0;

  for (i = 0; i < strlen(str); i++) {
    if (startc == 1)
      j++;
    if (str[i] == c)
      startc = 1;
  }
  return j-1;
}

/* sorted_print: take in a list of char pointers and sort them by the last integer in array */
void sorted_print(const char *list[], int entrys)
{
  int loc1, loc2;
  int i, j;
  const char *tmp_ptr;

  for (i = 0; i < entrys; i++) {
    for (j = 0; j < entrys; j++) {
      loc1 = index_array(list[i], ':');  // index the integer chars at list[i]
      loc2 = index_array(list[j], ':');  // index the integer chars at list[j]
      if (isspace(list[i][0]) && isspace(list[j][0])) {
        /* convert the ASCII string into an integer, then compare them... */
        if (atoi(list[i]+strlen(list[i])-loc1) > atoi(list[j]+strlen(list[j])-loc2))
        {
          tmp_ptr = list[i];
          list[i] = list[j];
          list[j] = tmp_ptr;
        }
      }
    }
  }
  /* print the ordered list / char ptr array */
  for (i = 0; i < entrys; i++)
    printf("%s \n", list[i]);
}

struct tnode * talloc(void);
char *strdup2(char *);

/* addtree: add a node with w, at or below p */
struct tnode * addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup2(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
     p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

/* treeassign: assign all notes into a ptr array */
int treeassign(struct tnode *p, const char *ptrs[], int n)
{
  static int i = 0;
  char word[MAXWORD];

  /* limit writes to the char ptr array */ 
  if (i == n)
    return i;

  if (p != NULL) {
    treeassign(p->left, ptrs, n);
    snprintf(word, MAXWORD, "%10s: %d", p->word, p->count);
    ptrs[i++] = strdup2(word);
    treeassign(p->right, ptrs, n);
  }

  return i;
}

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup2(char *s)
{
  char *p;
  p = (char *) malloc(strlen(s)+1); 
  if (p != NULL)
    strcpy(p, s);
  return p;
}
