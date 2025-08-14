#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push a character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/* skipper: skip string invalid data e.g: preprocessor lines, strings, comments, spaces */
int skipper(int retval)
{
  /* within processor line */
  if (retval == '#')
    while (retval != '\n')
      retval = getchar();

  /* within a comment block */
  else if ((retval == '/') && (retval = getchar()) == '*') {
    while (1) {
      retval = getchar();
      if (retval == '*')
        if ((retval = getchar()) == '/')
          break;
    }
  }
  /* within string constant */
  else if (retval == '"')
    while ((retval = getchar())!= '"')
      ;
  /* within space */
  else if (retval == ' ')
    ;
  else
    return 0;

  return retval;
}

/* getword: get next word or chracter from input */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (skipper(c = getch()))
    ; 

  if (c != EOF)
    *w++ = c;
  if(!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
