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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const intl M = 123, inf = 1000000000000000LL;

intl dp[M][M];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    int c, s, q, caseno = 1,a ,b, w;
    while(1)
    {
        cin >> c >> s >> q;
        if( c == 0 && s == 0 && q == 0 ) break;
        for( int i = 1; i <= c; i++ )
        {
            for( int j = 1; j <= c; j++ )
            {
                dp[i][j] = inf;
                if(i==j) dp[i][j] = 0;
            }
        }
        for( int i = 0; i < s; i++ )
        {
            cin >> a >> b >> w;
            dp[a][b] = w;
            dp[b][a] = w;
        }

        for( int i = 1; i <= c; i++ )
        {
            for( int j = 1; j <= c; j++ )
            {
                for( int k =1; k <= c; k++ )
                {
                    dp[j][k] = min( dp[j][k], max( dp[j][i], dp[i][k] ) );
                }
            }
        }
        if( caseno != 1 ) cout << endl;
        cout << "Case #" << caseno++ << endl;
        while(q--)
        {
            cin >> a >> b;
            if( dp[a][b] == inf )
            {
                cout << "no path" << endl;
            }
            else
            {
                cout << dp[a][b] << endl;
            }
        }

    }
    return 0;
}
