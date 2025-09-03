/*

Write a cross-referencer that prints a list of all words in a document, and,
for each word, a list of the line numbers on which it occurs. Remove noise
words like "the," "and," and so on.

A: So for example:

  Milton: 1, 2, 3, 4
          ^  ^  ^  ^
          |  |  |  |
          --------------- line numbers

Compile:
  gcc -ansi <program>

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "custom_getword.h"

#define MAXLINE 100 /* max number of lines */
#define MAXWORD 100 /* max string */

char *noise_words[]={"the", "and", "a", "a", "as"};

#define NKEYS sizeof(noise_words) / sizeof(noise_words[0])

struct tnode {
  char *word;           /* points to the string      */
  int lines[MAXLINE];   /* buffer containing lines   */
  int linecnt;          /* int containing # of lines */
  struct tnode *left;   /* left child                */
  struct tnode *right;  /* right child               */
};

struct tnode *addtree(struct tnode *, char *, int );
char * convert_to_lower(char *);
void treeprint(struct tnode *);

int main(int argc, char *argv[])
{
  int lines = 1;
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
  {
    if (lines == (MAXLINE-1))
      break;
    if (word[strlen(word)-1] == '\n')
      lines++;
    else {
      if (!(in_list(noise_words, convert_to_lower(word), NKEYS)))
        root = addtree(root, word, lines);
    }
  }
  treeprint(root);
  return 0;
}

/* convert_to_lower: converts a string to a lowercase string */
char * convert_to_lower(char *w)
{
  char tmp_buffer[MAXWORD];
  char *tmp_ptr;

  /* set the entire array to NULL bytes for every word */
  memset(tmp_buffer, '\0', sizeof(char)*MAXWORD);

  int i;
  for (i = 0; i < strlen(w); i++)
    tmp_buffer[i] = tolower(w[i]);
  tmp_ptr = &tmp_buffer[0];

  return tmp_ptr;
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
struct tnode * addtree(struct tnode *p, char *w, int cline)
{
  int cond;

  if (p == NULL)
  {
    p = talloc();
    p->word     = strdup(w);  /* the word */
    p->lines[0] = cline;      /* the line number */
    p->linecnt  = 1;          /* next index if we encounter this word again */
    p->left = p->right = NULL;
  }
  else if ((cond = strcmp(w, p->word)) == 0)
    p->lines[p->linecnt++] = cline;
  else if (cond < 0)
    p->left = addtree(p->left, w, cline);
  else
    p->right = addtree(p->right, w, cline);
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  int i;

  if (p != NULL) {
    treeprint(p->left);
    printf("%10s: ", p->word);
    for (i = 0; i < p->linecnt; i++)
      printf("%d, ", p->lines[i]);
    printf("\n");
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
