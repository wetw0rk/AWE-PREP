#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {        /* table entry: */
  struct nlist *next; /* next entry in chain */
  char *name;         /* defined name */
  char *defn;         /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: from hash value for string */
unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;
  return NULL;
}

char *strdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
    free ((void *) np->defn);
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

/* undef: remove (name, defn) in hashtab */
struct nlist *undef(char *name)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) != NULL) {
    free ((struct nlist *) np);
  }
  return np;
}

int main()
{
  struct nlist *test;

  char example[]="apples";

  install(example, "hello");
  install(example, "boi");

  test = lookup("apples");

  printf("The memory address of test is: %p\n", (void *) &test);
  printf("apples: %s\n", test->defn);

  undef(example);

  printf("The memory address of test is: %p\n", (void *) &test);
  if ((test = lookup("apples")) == NULL)
    printf("apples is not in the hashtable\n");

  return 0;
}
