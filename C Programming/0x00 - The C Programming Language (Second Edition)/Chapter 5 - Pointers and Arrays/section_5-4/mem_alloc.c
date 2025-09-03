#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc  */
static char *allocp = allocbuf;  /* next free position */

/* alloc: return a pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp-n; /* old p */
    } else /* not enough room */
        return 0;
}

/* afree: free storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int main()
{
    char *ptr2buf;
    char *ptr2buf2;

    printf("\n[starting the program and variables have beed declared   ]\n");
    printf("+--------------------------------------------------------+\n");
    printf("|   Variable   |   Address  | Points to  |     Value     |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|  allocbuf[]  | 0x%x |  NOTHING   |      0x%x      |\n", &allocbuf, *allocbuf);
    printf("+--------------------------------------------------------+\n");
    printf("|   *allocp    | 0x%x | 0x%x |      0x%x      |\n", &allocp, allocp, *allocp);
    printf("+--------------------------------------------------------+\n");
    printf("|  *ptr2buf    | 0x%x |  NOTHING   |      0x%x      |\n", &ptr2buf, ptr2buf);
    printf("+--------------------------------------------------------+\n");
    printf("| *ptr3buf2    | 0x%x |  NOTHING   |      0x%x      |\n", &ptr2buf2, *ptr2buf2);
    printf("+--------------------------------------------------------+\n\n");
    ptr2buf = alloc(9); /* allocate 9 bytes for ptr2buf */

    printf("[after calling alloc and the function returning a pointer]\n");
    printf("+--------------------------------------------------------+\n");
    printf("|   Variable   |   Address  | Points to  |     Value     |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|  allocbuf[]  | 0x%x |  NOTHING   |      0x%x      |\n", &allocbuf, *allocbuf);
    printf("+--------------------------------------------------------+\n");
    printf("|   *allocp    | 0x%x | 0x%x |      0x%x      |\n", &allocp, allocp, *allocp);
    printf("+--------------------------------------------------------+\n");
    printf("|  *ptr2buf    | 0x%x | 0x%x |      0x%x      |\n", &ptr2buf, ptr2buf, *ptr2buf);
    printf("+--------------------------------------------------------+\n");
    printf("| *ptr3buf2    | 0x%x |  NOTHING   |      0x%x      |\n", &ptr2buf2, *ptr2buf2);
    printf("+--------------------------------------------------------+\n\n");
    strcpy(ptr2buf, "APPLES");

    printf("[after calling strcpy(ptr2buf, \"APPLES\");                ]\n");
    printf("+--------------------------------------------------------+\n");
    printf("|   Variable   |   Address  | Points to  |     Value     |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|  allocbuf[]  | 0x%x |  NOTHING   |      0x%x     |\n", &allocbuf, *allocbuf);
    printf("+--------------------------------------------------------+\n");
    printf("|   *allocp    | 0x%x | 0x%x |      0x%x      |\n", &allocp, allocp, *allocp);
    printf("+--------------------------------------------------------+\n");
    printf("|  *ptr2buf    | 0x%x | 0x%x |      0x%x     |\n", &ptr2buf, ptr2buf, *ptr2buf);
    printf("+--------------------------------------------------------+\n");
    printf("| *ptr3buf2    | 0x%x |  NOTHING   |      0x%x      |\n", &ptr2buf2, *ptr2buf2);
    printf("+--------------------------------------------------------+\n\n");
    ptr2buf2 = alloc(6);

    printf("[after calling alloc and the function returning a pointer]\n");
    printf("+--------------------------------------------------------+\n");
    printf("|   Variable   |   Address  | Points to  |     Value     |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|  allocbuf[]  | 0x%x |  NOTHING   |      0x%x     |\n", &allocbuf, *allocbuf);
    printf("+--------------------------------------------------------+\n");
    printf("|   *allocp    | 0x%x | 0x%x |      0x%x      |\n", &allocp, allocp, *allocp);
    printf("+--------------------------------------------------------+\n");
    printf("|  *ptr2buf    | 0x%x | 0x%x |      0x%x     |\n", &ptr2buf, ptr2buf, *ptr2buf);
    printf("+--------------------------------------------------------+\n");
    printf("| *ptr3buf2    | 0x%x |  NOTHING   |      0x%x      |\n", &ptr2buf2, *ptr2buf2);
    printf("+--------------------------------------------------------+\n\n");    
    strcpy(ptr2buf2, "BERRY");

    printf("[after calling strcpy(ptr2buf2, \"BERRY\");                ]\n");
    printf("+--------------------------------------------------------+\n");
    printf("|   Variable   |   Address  | Points to  |     Value     |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|  allocbuf[]  | 0x%x |  NOTHING   |      0x%x     |\n", &allocbuf, *allocbuf);
    printf("+--------------------------------------------------------+\n");
    printf("|   *allocp    | 0x%x | 0x%x |      0x%x      |\n", &allocp, allocp, *allocp);
    printf("+--------------------------------------------------------+\n");
    printf("|  *ptr2buf    | 0x%x | 0x%x |      0x%x     |\n", &ptr2buf, ptr2buf, *ptr2buf);
    printf("+--------------------------------------------------------+\n");
    printf("| *ptr3buf2    | 0x%x |  NOTHING   |      0x%x     |\n", &ptr2buf2, *ptr2buf2);
    printf("+--------------------------------------------------------+\n");

    printf("\n\n&ptr2buf  = 0x%x -> 0x%x -> %s\n", &ptr2buf, ptr2buf, ptr2buf);
    printf("&ptr2buf2 = 0x%x -> 0x%x -> %s\n", &ptr2buf2, ptr2buf2, ptr2buf2);
    printf("&allocbuf = 0x%x -> %s\n", &allocbuf, allocbuf);
}
