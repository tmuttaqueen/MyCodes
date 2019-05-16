#include <stdio.h>
int main()
{
    int n,i,sp,st;

    printf("Enter value: ");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        for(sp=1; sp<=n-i; sp++)
        {
            printf(" ");
        }
        for(st=1; st<=(2*i-1); st++)
        {
            printf("*");
        }
        printf("\n");
        printf("yes");
    }

    for(i=1; i<n; i++)
    {
        for(sp=1; sp<=i; sp++)
        {
            printf(" ");
        }
        for(st=1; st<=(2*(n-i)+1); st++)
        {
            printf("*");
        }
        printf("\n");
        printf("yes");
    }


    return 0;
}
