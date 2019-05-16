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
int n, q;
intl ara[100005], col[100005], dp[100005], used[100005];

intl solve( intl a, intl b )
{
    intl c1 = -1, c2 = -1, mx1 = 0, mx2 = 0, mx = 0;
    memset( used, 0, sizeof used );
    memset( dp, 0, sizeof dp );
    //for( int i = 1; i <= n; i++ ) dp[i] = -1e18;
    for( int i = 1; i <= n; i++ )
    {
        int c = col[i];

        if( used[c] == 0 )
        {
            dp[c] = mx1+ara[i]*b;
        }
        else
        {
            dp[c] = max( dp[c], dp[c] + a*ara[i] );
            if( c != c1 )
            {
                dp[c] = max( dp[c], dp[c1]+ b*ara[i] );
            }
            else if( c != c2 )
            {
                dp[c] = max( dp[c], dp[c2]+ b*ara[i] );
            }
        }

        if( dp[c] >= mx1 )
        {
            if( c != c1 )
            {
                swap(c1, c2);
                c1 = c;
                swap(mx1, mx2);
                mx1 = dp[c];
            }
            else
            {
                mx1 = dp[c];
            }
        }
        else if( dp[c] >= mx2 )
        {
            c2 = c;
            mx2 = dp[c];
        }
        used[c] = 1;
        mx = max( mx, dp[c] );
        if( c1 == c2 && c1 != -1 ) while(1);
        //cout << i << " col " << c << " " << dp[c] << " " << mx1 << " " << mx2 << endl;

    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> n >> q;
    for( int i=  1; i <= n; i++ )
        cin >> ara[i];
    for( int i =  1; i <= n; i++ )
        cin >> col[i];
    while(q--)
    {
        intl a, b;
        cin >> a >> b;
        cout << solve( a, b ) << endl;
    }

    return 0;
}
