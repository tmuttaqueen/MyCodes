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
#define pii         pair<intl, intl>
#define piii        pair<intl, pii>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl inf = 1000000000000000LL;

int flag[21111111];
vector<pii>vec[1111111], vecc[1111111];
intl f[2111111];
intl s[2111111];
intl low[2111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, m, k;
    intl a, x ,y ,c;
    cin >> n >> m >> k;
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> x >> y >> c;
        if( x == 0 )
        {
            vecc[a].pb( mp(y, c) );
        }
        else
            vec[a].pb( mp( x, c ) );
    }

    c = 0;
    int ind = 0;
    memset( flag, 0, sizeof flag );
    intl cost = 0;
    int d1 = -1, d2 = -1;
    for( int i = 0; i <= n; i++ ) low[i] = inf;
    for( int i = 1; i <= 1000000; i++ )
    {
        s[i] = inf;
        for( pii x: vec[i] )
        {
            intl ct = x.xx, cs = x.yy;
            if( flag[ct] == 0 )
            {
                flag[ct] = 1;
                cost += cs;
                low[ct] = cs;
                c++;
            }
            else if( low[ct] > cs  )
            {
                cost -= low[ct];
                low[ct] = cs;
                cost += cs;
            }
        }
        if( c == n )
        {
            s[i] = min( s[i], cost );
        }
    }

    c = 0;
    ind = m-1;
    memset( flag, 0, sizeof flag );
    cost = 0;

    for( int i = 0; i <= n; i++ )
        low[i] = inf;

    for( int i = 1000000; i>=1; i-- )
    {
        f[i] = inf;
        for( pii x: vecc[i] )
        {
            intl ct = x.xx, cs = x.yy;
            if( flag[ct] == 0 )
            {
                flag[ct] = 1;
                cost += cs;
                low[ct] = cs;
                c++;
            }
            else if( low[ct] > cs  )
            {
                cost -= low[ct];
                low[ct] = cs;
                cost += cs;
            }
        }
        if( c == n )
        {
            f[i] = min( f[i], cost );
        }
    }


    intl ans = inf;
    for( int i = 1; i <= 1000000; i++ )
    {
        if( i+k+1 <= 1000000 )
        {
            ans = min( ans, s[i]+f[i+k+1] );
        }
    }
    if( ans >= inf || ans <= 0 )
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}

