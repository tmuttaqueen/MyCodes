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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

pii tree[500000];
intl inf = 10000000000000000LL;
intl dp[100005];

pii query( int cn, int s, int e, int x, int y )
{
    if( s >= x && e <= y )
        return tree[cn];
    if( s > y || e < x )
        return mp(0,0);
    int m = (s+e)/2;
    pii l = query( cn*2, s , m, x, y );
    pii r = query( cn*2+1, m+1, e, x, y );
    return max(l,r);
}

void update( int cn, int s, int e, int x, int y, int v )
{

    if( s > y || e < x )
        return ;
    if( s >= x && e <= y )
    {
        tree[cn].xx = v;
        tree[cn].yy = x;
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, y, v );
    update( cn*2+1, m+1, e, x, y, v );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
    return;
}

int ara[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    intl ans = 1;
    cin >> n;
    for( int i = 1; i < n; i++ ) cin >> ara[i];
    for( int i = 1; i < n; i++ ) update( 1, 1, n, i,i, ara[i] );
    dp[n] = 0;
    dp[n-1] = 1;
    for( int i = n-2; i > 0; i-- )
    {
        int l = i+1, r = ara[i];
        if( r == n )
        {
            ans += n-i;
            dp[i] = n - i;
            continue;
        }
        pii x = query( 1, 1, n, l, r );
        intl d = 0;
        d += dp[x.yy] + n-x.yy;
        d -= (r-x.yy);
        d += x.yy-i;
        ans+=d;
        dp[i] = d;
    }
    //for( int i = 1; i <= n; i++ ) cout <<dp[i] << " ";
    //cout << endl;
    cout << ans << endl;
    return 0;
}



