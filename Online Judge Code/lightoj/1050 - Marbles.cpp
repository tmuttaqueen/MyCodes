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

double dp[505][505];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    double a, b, s, ans;
    for( int i = 0; i <= 500; i++ )
        dp[0][i] = 1;
    for( int i = 1; i <= 500; i++ )
    {
        int j;
        j = (i%2)?0:1;
        for( ; j <= 500; j += 2 )
        {
            if( i > j )
            {
                dp[i][j] =  0;
            }
            else
            {
                a = i; b = j; s = a+b;
                ans = (a*dp[i-1][j-1] + b*dp[i][j-2])/s;
                dp[i][j] = ans;
            }
        }
    }
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        printf("Case %d: %.10lf\n", caseno++, dp[p][q]);
    }
    return 0;
}



