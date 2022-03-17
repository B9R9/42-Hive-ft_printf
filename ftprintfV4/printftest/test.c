#include <stdio.h>

int main(void)
{
    char *a;

    a = "ABCDREFHGV";

    printf("%.*s",5, a );
    return (0);
}