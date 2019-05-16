#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t );
    while( t-- )
    {
        int n;
        int sum = 0;
        scanf("%d", &n);
        int ara[n+4];
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &ara[i]);
            if( i > 0)
            {
                for( int j = 0; j < i; j++ )
                {
                    if( ara[j] <= ara[i] )
                        sum++;
                }
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
