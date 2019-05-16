#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define pdd         pair<double, double>


int main()
{
    //ios::sync_with_stdio(false);
    filein;
    while(1)
    {
        int n, k, tt;
        double x;
        scanf("%d %d %d", &n, &k, &tt);
        if( n == 0 && k == 0 && tt == 0 ) break;
        x = tt;
        double a, b, c, l, p, t1, t2;
        pdd ara[n+5];
        double dp[n+5][k+5];
        for( int i = 0; i < n; i++ )
        {
            scanf("%lf %lf %lf", &a, &l, &p);
            t1 = a*p/100;
            t2 = 1 - l*(100-p)/10000;
            ara[i] = mp(t1,t2);
            dp[1][i] = t1 + x*t2;
        }

        for( int i = 2; i <= k ; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                double temp = -10000000000000.0;
                a = ara[j].xx;
                b = ara[j].yy;
                for( int g = 0; g < n; g++ )
                {
                    if( g != j )
                        temp = max( temp, a+b*dp[i-1][g] );
                }
                dp[i][j] = temp;
            }
        }

        double ans = -10000000000000.0;
        for( int i = 0; i < n; i++ ) ans = max(ans, dp[k][i]);
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}


