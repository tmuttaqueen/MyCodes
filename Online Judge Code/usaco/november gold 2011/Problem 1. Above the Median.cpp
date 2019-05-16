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
#define filein      freopen("I.10", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

///1D BIT O(logn)
const int mx = 100005;
int bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}

int pre[mx], ara[mx], data[mx];
pii t[mx];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    int n, k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    ara[0] = 0;
    for( int i = 1; i <= n; i++ )
    {
        pre[i] = pre[i-1];
        if( ara[i] >= k ) pre[i]++;
        //data[i] = 2*pre[i]-i;
        t[i] = mp( 2*pre[i]-i, i );
    }
    sort( t+1, t+n+1 );
    intl ans = 0;
    for( int i =1; i <= n; i++ )
    {
        ans += query( t[i].yy );
        if( t[i].xx >= 0 ) ans++;
        update( t[i].yy, 1 );
    }
    cout << ans << endl;
    return 0;
}
