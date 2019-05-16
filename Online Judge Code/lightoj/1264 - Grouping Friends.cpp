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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

int ara[20][20], tot;
int dp[1<<15], val[1<<15];

inline int calc( int n )
{
    int p = 0;
    vector<int>t;
    for( int i = 0; i < tot; i++ )
    {
        if( n&(1<<i) )
            t.pb(i);
    }
    for( int i = 0; i < t.size(); i++ )
    {
        for( int j = 0; j < t.size(); j++ )
        {
            p += ara[ t[i] ][ t[j] ];
        }
    }
    return p;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &tot);
        for( int i = 0; i < tot; i++ )
        {
            for( int j = 0; j < tot; j++ )
            {
                scanf("%d", &ara[i][j]);
            }
        }
        int mask = (1<<tot)-1;
        for( int i = 0; i <= mask; i++ )
        {
            val[i] = calc(i);
        }
        memset( dp, -1, sizeof dp );
        dp[0] = 0;
        int mx = 1<<tot ;
        for( int mask = 1; mask < mx; mask++ )
        {
            int v = 1e9;
            for( int i = mask; i > 0; i = (i-1)&mask )
            {
                v = min( v, val[i] + dp[i^mask] );
            }
            dp[mask] = v;
        }
        int ans = dp[mx-1];
        printf("Case %d: %d\n", caseno++, ans);
    }
    return 0;
}
