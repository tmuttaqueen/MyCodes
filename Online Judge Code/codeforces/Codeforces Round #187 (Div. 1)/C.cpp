#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl ara[100005], flag[1000005];
intl previous[100005];
intl ans[100005];

///1D BIT O(logn)
const int mx = 1000002;
intl mod = 1e9 + 7;
intl bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        bit[x] %= mod;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    if( x == 0 ) return 0;
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        sum %= mod;
        x -= (x&(-x));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++  )
    {
        cin >> ara[i];
        if( flag[ ara[i] ] != 0 )
        {
            previous[i] = flag[ ara[i] ];
        }
        flag[ ara[i] ] = i;
    }

    memset( flag, 0, sizeof flag );
    ans[1] = ara[1];
    flag[ ara[1] ] = ara[1];
    update( ara[1], ara[1] );

    for( int i = 2; i <= n; i++ )
    {
        intl d = query(ara[i]) - flag[ ara[i] ];
        d %= mod;
        d = (d+mod)%mod;
        if( flag[ ara[i] ] != 0 )
            d += ans[ previous[i] ];
        if( previous[i] == 0 )
            d += 1;
        d %= mod;
        if( d < 0 ) while(1);
        ans[i] = (d*ara[i])%mod;
        update( ara[i], ans[i] );
        flag[ ara[i] ] = query( ara[i] );
        //what_is( ans[i] );
        /*
        ans[i] = ( ans[ previous[i] ]*ara[i] )%mod;

        if( previous[i] != 0 )
        {
            intl d = query( ara[i] );
            d -= fl
        }
        else
        {
            intl q = query( ara[i] );
            ans[i] = (q*ara[i])%mod;
            ans[i] = ( ans[i] + ara[i] )%mod;
            //what_is( ans[i] );
            update( ara[i], ans[i] );
        }*/
    }
    intl sum = 0;
    for( int i =0; i <= n; i++  ) sum = (sum+ans[i])%mod;
    cout << sum << endl;
    return 0;
}




