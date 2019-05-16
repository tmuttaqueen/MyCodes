#include<bits/stdc++.h>

using namespace std;

#define intl long long

const int mx = 1e5+5;

intl x[mx], y[mx], lr[mx], rl[mx];

int main()
{

    int t;
    scanf("%d", &t);
    while(t--)
    {

        memset( lr, 0, sizeof lr );
        memset( rl, 0, sizeof rl );
        int n, q;
        scanf("%d %d", &n, &q);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%lld %lld", &x[i], &y[i]);
        }
        for( int i = 2; i < n; i++ )
        {
            intl d = ( y[i+1]-y[i-1] )*(x[i]-x[i-1]) - (y[i]-y[i-1])*(x[i+1]-x[i-1]);
            if( d < 0  )
            {
                lr[i] = 3;
                rl[i] = 1;
            }
            else if( d > 0 )
            {
                lr[i] = 1;
                rl[i] = 3;
            }
            else
            {
                lr[i] = 0;
                rl[i] = 0;
            }
        }
        for( int i = 1; i <= n; i++ )
        {
            lr[i] += lr[i-1];
            rl[i] += rl[i-1];
        }

        while(q--)
        {
            int s, t;
            scanf("%d %d", &s, &t);

            if( t - s >= 2 )
            {
                printf("%lld\n", lr[t-1] - lr[s]  );

            }
            else if( s-t >= 2 )
            {
                printf("%lld\n", rl[s-1] - rl[t] );

            }
            else
                printf("0\n");

        }
    }
    return 0;
}
