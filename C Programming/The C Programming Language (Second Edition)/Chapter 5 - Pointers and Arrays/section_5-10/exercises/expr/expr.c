/*
 
Write the program expr, which evaluates a reverse Polish
expression from the command line, where each operator is
a seperate argument.

For example:
  expr 2 3 4 + *
evaluates to:
    2 * (3+4)

Note: On Linux run expr 2 3 4 + '*'

Vuln: touch a file of 225 A's as the filename and run `expr 2 3 4 + *`

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP  100
#define NUMBER '0'

void push(double);
double pop(void);

int main(int argc, char *argv[])
{
  double op2;
  char s[MAXOP];
  int type, c, i = 1;

  while (i != argc)       /* loop until we are done processing user args      */
  {
    c = (argv[i])[0];     /* place the character in c rather than the string */
    if (isdigit(c))       /* if we have an into set type to '0' for a number */
      type = NUMBER;
    else                  /* else store the char into the type */
      type = c; 

    strcpy(s, argv[i]);   /* store the string arg (e.g "9\0") into s */

    /*
    the below code remains the same, the only change is now the equation
    is processed when there are no more args instead of a newline.
    */
    switch(type)
    {
      case (NUMBER):
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
    i++; /* increment the index to address */
  }
  printf("\t%.8g\n", pop()); /* done with args calculate */
  return(0);
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position   */
double val[MAXVAL]; /* value stack                */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

