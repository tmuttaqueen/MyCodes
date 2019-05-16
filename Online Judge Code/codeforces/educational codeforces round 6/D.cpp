#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n,m, w1[2], w2[2], c = 0;
    long long s1=0,s2=0;
    bool flag = 0;
    long long ara1[2001], ara2[2001];
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        scanf("%lld", &ara1[i]);
        s1 += ara1[i];
    }
    cin >> m;
    for( int i = 0; i < m; i++ )
    {
        scanf( "%lld", &ara2[i] );
        s2 += ara2[i];
    }
    long long d;
    d = s1 - s2;
    if( d < 0 )
    {
        d = -d;
        flag = 1;
    }
    long long t = 0, p, q;
    if( flag == 1 )
    {
        for( int i = 0; i < m; i++ )
        {
            //long long x = ara2[i];
            for( int j = 0; j < n; j++ )
            {
                if( ara2[i] > ara1[j] )
                {
                    long long y = ara2[i] - ara1[j];
                    if( (2*y-d)  )
                }
            }
        }
    }
    d -= t;
    w1[0] = p;
    w2[0] = q;
    if(  )
    if(  )
    return 0;
}
