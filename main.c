#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void get_num(char **p)
{
    *p = malloc(100);
}
// int main(int argc, char const *argv[])
// {
//     char *s;
//     get_num(&s);
//     strcpy(s, "HELLO");
//     puts(s);
//     //printf("hello\n");
//     return 0;
// }


int main(int argc, char const *argv[])
{
    int i = 10;
    char *p;
    p = (char*)&i;
    if (10 == *p)
    {
        printf("da\n");
    }
    else
    {
        printf("xiao\n");
    }
    return 0;
}

