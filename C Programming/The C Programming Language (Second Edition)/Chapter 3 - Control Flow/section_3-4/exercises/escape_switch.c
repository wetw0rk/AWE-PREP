/*
write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to,
s. use a switch. write a function for the other direction as well, convert
escape sequences into real characters.
*/

#include <stdio.h>

#define MAXBUFF 1000

void escape(char s[], char t[])
{
    int c = 0, i = 0;

    while (t[i] != '\0')
    {
        switch(t[i])
        {
            /*
            if an escape character is identified, replace/assign 2 bytes to
            2 index locations e.g [0] = '\\', [1] = 'n'. then increment i++
            for the next var (after all \n is one byte not 2)
            */
            case '\n':
                s[c++] = '\\';
                s[c++] = 'n';
                i++;
                break;
            case '\t':
                s[c++] = '\\';
                s[c++] = 't';
                i++;
                break;
        }
        /* assign character to new strings appropriate index */
        s[c++] = t[i++];
    }
}

void escape2char(char s[], char t[])
{
    int i = 0;

    while (t[i] != '\0')
    {
        switch(t[i])
        {
            case '\n':
                s[i++] = 'n';
                break;
            case '\t':
                s[i++] = 't';
                break;
        }
        s[i++] = t[i];
    }
}


int main()
{
    char t[]= "ABCDEFG\nAAAA\tBBBB\nGGG\n\0";
    char s[MAXBUFF];

    escape2char(s, t);

    printf("t = %s",     t);
    printf("\ns = %s\n", s);

    return(0);
}
