/*

Add commands tp print the top element of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear
the stack.

Compile: gcc pElement.c -g3 -o pElement.c

*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP   100 /* max size of operand or operator */
#define NUMBER  '0' /* signal that a number was found  */

int getop(char []);
void push(double);
double pop(void);
void clearsp();

/* reverse polish calculator */
int main()
{
    int type;
    double op2;
    double op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
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
            case '%':
                op1 = pop();
                op2 = pop();
                push((int) op2 % (int) op1);
                break;
            case 'c':
                clearsp();
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case '?':
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            defualt:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
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

void clearsp()
{
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    /* this handles the negative numbers */
    if (c == '-')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
        /* if we get a minus vs a negative what follows is a newline */
        if (c == '\n')
        {
            ungetch(c); /* ungetch the newline in 4 next loop */
            return '-';
        }
    }
    
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

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
