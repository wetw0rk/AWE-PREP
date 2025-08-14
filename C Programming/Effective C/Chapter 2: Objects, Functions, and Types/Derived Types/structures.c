/*

A structure type (also known as a struct) contains allocated member objects. Each object
has its own name and may have a distinct type - unlike arrays.

*/

#include <stdio.h>
#include <string.h>

 /* declares a struct object identified by sigline, and a pointer to a
    sigline object identified by sigline_p */
struct sigrecord
{
  int signum;
  char signame[20];
  char sigdesc[100];
} sigline, *sigline_p;

int main(void)
{
  sigline.signum = 9;
  strcpy(sigline.signame, "SIGINT");
  strcpy(sigline.sigdesc, "Interrupt from keyboard");
  printf("Signum: %d, Signame: %s, Sigdesc: %s\n", sigline.signum, sigline.signame, sigline.sigdesc);

  sigline_p = &sigline; /* assign the pointer to sigline_p to the address of the sigline object */

  sigline_p->signum = 6;
  strcpy(sigline_p->signame, "SIGINT");
  strcpy(sigline_p->sigdesc, "Interrupt from keyboard");
  printf("Signum: %d, Signame: %s, Sigdesc: %s\n", sigline.signum, sigline.signame, sigline.sigdesc);
}
