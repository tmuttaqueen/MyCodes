#include <bits/stdc++.h>
#include <stdint.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        unsigned long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl gcd( intl a, intl b )
{
    if(a==0) return b;
    return (b == 0)? a: gcd(b,a%b);
}


intl dp[30][200];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno=1;

    dp[0][0] = 0;
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1;
    dp[1][0] = 0;
    for( int i = 7; i < 200; i++ ) dp[1][i] = 0;

    for( int i = 2; i <= 25; i++ )
    {
        dp[i][0] = 0;
        for( int j = 1; j <= i*6; j++ )
        {
            intl ans = dp[i-1][j-1];
            for( int k = 2; k <= 6; k++ )
            {
                if( j - k < 0 )
                    break;
                ans += dp[i-1][j-k];
            }
            dp[i][j] = ans;
        }
    }
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        intl ans = dp[a][b];
        for( int i = b+1; i <= a*6; i++ ) ans += dp[a][i];
        intl temp = 1;
        for( int i = 0; i < a; i++  ) temp*=6;
        intl g = gcd( temp, ans );
        ans /= g;
        temp /= g;

        if( temp == 1 )
        {
            printf("Case %d: %lld\n", caseno++, ans );
        }
        else
            printf("Case %d: %lld/%lld\n", caseno++, ans, temp );
    }

    return 0;
}




