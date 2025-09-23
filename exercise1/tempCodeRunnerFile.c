# include <stdio.h>
int main()
{
    int a = 5, b;
    printf("Pattern using DO...WHILE loop:\n");
    do {
        b = 1;
        do {
            printf("* ");
            b++;
        } while(b <= a);
        printf("\n");
        a--;
    } while(a >= 1);
    return 0;
}