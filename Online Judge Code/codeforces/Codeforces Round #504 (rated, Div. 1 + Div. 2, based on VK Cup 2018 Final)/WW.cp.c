#include<stdio.h>

int main()
{
    int a = 100, b = 90;

    int c = 90;
    while( c >= 1 )
    {
        if( a%c == 0 && b%c == 0 )
        {
            break;
        }
        c = c - 1;
    }
    printf("%d\n", c);

}
