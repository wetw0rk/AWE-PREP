/*

Revise miniprintf to handle more of the other facilities of printf

A: Note this is really shitty and I only included ways to handle
   string formating such as %10s and %-10s. Can be made better!!
 
*/

#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define ISDIGIT(x) (x >= '0' && x <= '9') ? 1 : 0

#define MAXNUM 2 /* Maximum number betweeen fmt str e.g:%<num>s */


/* get_number: get a string pointer and iterate through integers */
int get_number(char *s)
{
  int i = 0;
  int counter = 0;
  int len = strlen(s);
  char tmp_buffer[MAXNUM+1];

  if (ISDIGIT(s[0]))
  {
    while (i < len)
    {
      if (i < (MAXNUM) && ISDIGIT(s[0]))
      {
        tmp_buffer[i++] = *s++, counter++;
      }
      else
        break;
    }
    tmp_buffer[counter] = '\0';
  }
  return atoi(tmp_buffer);
}

/* print_space: just print spaces based on number provided */
void print_space(int n)
{
  for (int i = 0; i < n; i++)
    putchar(' ');
}

/* format_adjust: return int that needs to be appended/prepended */
int format_adjust(char * strPTR)
{
  int i;
  int num = 0;

  if (ISDIGIT(strPTR[0]))
    num = get_number(strPTR);
  else if (strPTR[0] == '-')
    num = get_number(++strPTR);
  
  return num;
}

/* miniprintf: minimal printf with variable argument list */
void miniprintf(char *fmt, ...)
{
  va_list ap; /* points to each unnamed arg in turn */
  char *p;
  char *sval;
  int ival;
  int adj;        /* hold space adjustment returned from format_adjust() */
  int slen;       /* hold the lenth of the formatted string (before spaces) */
  int check = 0;  /* 1 == place spaces before string, 0 == after */
  double dval;

  va_start(ap, fmt); /* make ap point to 1st unamed arg */
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    /* send off to get adjustment */
    adj = 0, check = 0;
    if (isdigit(*++p)) {
      check = 1;
      adj = format_adjust(p++);
    }
    else if (*p == '-') {
      adj = format_adjust(p);
      p += MAXNUM;
    }
    else
      *--p;
  
    switch(*++p) {
      case 'd':
        ival = va_arg(ap, int);
        slen = snprintf(NULL, 0, "%d", ival);
        if (check == 1) {
          print_space(adj-slen);
          printf("%d", ival);
        }
        else {
          printf("%d", ival);
          print_space(adj-slen);
        }
        break;
      case 'f':
        dval = va_arg(ap, double);
        slen = snprintf(NULL, 0, "%f", dval);
        if (check == 1) {
          print_space(adj-slen);
          printf("%f", dval);
        }
        else {
          printf("%f", dval);
          print_space(adj-slen);
        }
        break;
      case 's':
        sval = va_arg(ap, char *);
        slen = snprintf(NULL, 0, "%s", sval);
        if (check == 1) {
          print_space(adj-slen);
          printf("%s", sval);
        }
        else {
          printf("%s", sval);
          print_space(adj-slen);
        }
        break;
      default:
        putchar(*p);
        break;
    }
  }
  va_end(ap);
}

int main()
{
  int d = 4;
  double f = 5.0;
  char str[]= "hi";

  miniprintf("[---Printing character strings-]\n");
  miniprintf(":%10s:\n", str);
  miniprintf(":%s:\n", str);
  miniprintf(":%-10s:\n", str);
  miniprintf(":%s:\n", str);

  miniprintf("\n[---Printing floats------------]\n");
  miniprintf(":%10f:\n", f);
  miniprintf(":%-10f:\n", f);
  miniprintf(":%f:\n", f);

  miniprintf("\n[---Printing integers----------]\n");
  miniprintf(":%10d:\n", d);
  miniprintf(":%-10d:\n", d);
  miniprintf(":%d:\n", d);

  return 0;
}
