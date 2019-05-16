#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int dp[44][44][555];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, s;
    while( cin >> n >> s )
    {
        if(n==0 && s==0) break;
        for( int i = 0; i <= 2*n; i++ )
        {
            for( int j = 0; j <= 2*n; j++ )
            {
                for( int k = 0; k <= s; k++ )
                {
                    dp[i][j][k] = 0;
                }
            }
        }
        int d =n, t = -1;
        for( int i = 1; i <= 2*n-1; i++ )
        {
            for( int j  = 1; j <= d; j++ )
            {
                cin >> ara[i][j];
            }
            d += t;
            if( d == 1 )
            {
                t += 2;
            }
        }
        for( int i =  n; i >= 1; i-- )
        {
            dp[2*n-1][i][s-ara[2*n-1][i] ] = 1;
        }
        d = n-1;
        t = -1;
        if(d==1)
            t = 1;
        for( int i = 2*n-2; i >= 1; i-- )
        {
            for( int j = 1; j <= d; j++  )
            {
                int l, r;
                if( i < n )
                {
                    l = j -1;
                    r = j;
                }
                else
                {
                    l = j;
                    r = j+1;
                }
                for( int k = 0; k <= s; k++ )
                {
                    if( l > 0 )
                    dp[i][j][k] =
                }
            }
            d += t;
            if( d == 1 )
            {
                t += 2;
            }
        }
    }
    return 0;
}
