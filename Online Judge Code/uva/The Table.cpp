#include<bits/stdc++.h>

using namespace std;

int ara[1234][12];
int neg[12];

int main()
{
    int n, m;
    while( cin >> m >> n )
    {
        memset( neg, 0, sizeof neg );
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
            {
                cin >> ara[i][j];
                if( ara[i][j] < 0 )
                    neg[j]++;
            }
        }
        int c = 0;
        for( int i = 1; i <= m; i++ )
            if( neg[i]%2 ) c++;
        int ans;
        //cout << c << endl;
        if( c == m )
        {
            ans = -1;
            double val = 1000000000.0;
            for( int i = 1; i <= m; i++ )
            {
                double d = 0;
                for( int j = 1; j <= n; j++ )
                {
                    d += log( (double)abs( ara[j][i] ) );
                }
                if(  d <= val )
                {
                    ans= i;
                    val = d;
                }
            }
        }
        else
        {
            ans = -1;
            double val = -1;
            for( int i = 1; i <= m; i++ )
            {
                if( neg[i]%2 ) continue;
                double d = 0;
                for( int j = 1; j <= n; j++ )
                {
                    d += log( (double)abs( ara[j][i] ) );
                }
                //cout << d << endl;
                if( d >= val )
                {
                    ans = i;
                    val = d;
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}
