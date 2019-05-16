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
#define filein      freopen("lifeguards.in", "r", stdin)
#define fileout     freopen("lifeguards.out", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 145678;

pii ara[M];
intl st[M], en[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    fileout;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i].xx >> ara[i].yy;
        st[i] = ara[i].xx;
        en[i] = ara[i].yy;
    }
    sort( ara, ara+n );
    sort( st, st+n );
    sort(en, en+n);
    intl tot = 0, cur = 0;
    bool flag = false;
    for( int i = 0; i < n; i++ )
    {
        if( ara[i].yy <= cur )
        {
            flag = true;

        }
        if( i < n - 1 && ara[i+1].xx == ara[i].xx )
        {
            flag = true;

        }
        tot += max( 0LL, ara[i].yy - max(cur, ara[i].xx ) );
        cur = max( cur, ara[i].yy);
        //cout << cur << " " << tot << endl;
    }
    if( flag )
    {
        cout << tot << endl;
        return 0;
    }
    intl ans = 0;
    for( int i = 0; i < n; i++ )
    {
        int s = lower_bound( en, en + n, ara[i].yy ) - en;
        int t = lower_bound( st, st + n, ara[i].xx ) - st;
        s--;
        t++;
        intl l = ara[i].xx, r = ara[i].yy;
        if( s >= 0 )
        {
            l = max( l, en[s] );
        }
        if( t < n )
        {
            r = min( r, st[t] );
        }
        ans = max( ans, tot - max(0LL, r - l) );
    }
    cout << ans << endl;

    return 0;
}
