/*

Define a macro swap(t,x,y) that interchanges two arguments of type t.

Macro execution flow:
    1. set z variable to type t
    2. overwrite z with x
    3. overwrite x with y
    4. overwrite y with z

*/

#include <stdio.h>

#define swap(t,x,y) {t z;  \
                    z = x; \
                    x = y; \
                    y = z; \
                    }

int main()
{
    char x='a', y='b';
    int x1=41, y1=42;

    printf("x=%c \t y=%c\n",x,y);
    swap(char,x,y);
    printf("x=%c \t y=%c\n",x,y);

    printf("x=%d \t y=%d\n",x1,y1);
    swap(int,x1,y1);
    printf("x=%d \t y=%d\n",x1,y1);

    return 0;
}
