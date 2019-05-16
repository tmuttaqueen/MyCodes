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
intl ara[40], m;
intl s[2][M];
int c[2];

void count( intl st, intl en, intl k )
{
    s[k][ c[k]++ ] = 0;
    for( int i = st; i <= en; i++ )
    {
        int d = c[k];
        for( int j = 0; j < d; j++ )
        {
            s[k][ c[k]++ ] = (s[k][j] + ara[i])%m;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        ara[i] %= m;
    }
    count( 0, n/2, 0 );
    count( n/2+1, n-1, 1 );
    sort( s[1], s[1] + c[1] );
    intl ans = 0;
    for( int i = 0; i < c[0]; i++ )
    {
        intl v = s[0][i];
        //cout << v << endl;
        ans = max(ans, v);
        int d1 = m-1-v, d2 = 2*m-1-v;
        int d = upper_bound( s[1], s[1]+c[1], d1 ) - s[1];
        if( d > 0 )
        {
            d--;
            ans = max( ans, (v+s[1][d])%m );
        }
        d = upper_bound( s[1], s[1]+c[1], d2 ) - s[1];
        if( d > 0 )
        {
            d--;
            ans = max( ans, (v+s[1][d])%m );
        }
    }
    cout << ans << endl;
    return 0;
}
