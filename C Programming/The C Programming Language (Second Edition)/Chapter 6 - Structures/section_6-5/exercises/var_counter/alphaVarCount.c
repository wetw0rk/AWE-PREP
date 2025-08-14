/*

Write a program that reads a C program and prints in alphabetical order each group
of variable names that are identical in the first 6 characters, but different some 
where thereafter. Don't count words within strings and comments. Make 6 a parameter
that can be set from the command line

A: The wording was a lil confusing so.. hopefully I got it

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "getword.h"

#define MAXWORD 100

char *keys[]= { "int", "char" };

#define NKEYS sizeof(keys) / sizeof(keys[0])

struct tnode {          /* the tree node:         */
  char *word;           /* points to the text     */
  int count;            /* number of occurrences  */
  struct tnode *left;   /* left child             */
  struct tnode *right;  /* right child            */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

int main(int argc, char *argv[])
{
  struct tnode *root;
  char word[MAXWORD];
  char tmp[MAXWORD];
  int incoming = 0;

  if (argc < 2) {
    printf("%s <first x number of chars to detect>\n", argv[0]);
    exit(-1);
  }
  int clen = atoi(argv[1]);

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
  {
    /* a vartype was detected meaning this is a variable*/
    if (incoming == 1 && isalpha(word[0])) {
      strncpy(tmp, word, clen);   /* group only first x chars */
      tmp[clen] = '\0';           /* NULL terminate the shit! */
      root = addtree(root,tmp);
      incoming = 0;
    }
    /* detects a vartype */
    if (isalpha(word[0]))
      incoming = in_list(keys, word, NKEYS);
  }
  treeprint(root);
  return 0;
}

/* inlist: check if a word is within a list */
int in_list(char *list[], char *word, int nkeys)
{
  int i;

  for (i = 0; i < nkeys; i++)
    if (strcmp(word, list[i]) == 0)
      return 1;
  return 0;
}

struct tnode * talloc(void);
char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode * addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup(w);
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

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}
