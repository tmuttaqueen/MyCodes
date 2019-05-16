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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

const int mx = 100;
int dp[mx][mx][mx][4]; //1 = v in last
vector<int>V, K, X, Vk, Vx, Kv, Kx, Xv, Xk;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    string s;
    cin >> n;
    cin >> s;
    int vv = 0, kk = 0, xx = 0;
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == 'V' )
        {
            vv++;
            V.pb(i);
            Vk.pb( K.size() );
            Vx.pb( X.size() );
        }
        else if( s[i] == 'K' )
        {
            kk++;
            K.pb(i);
            Kx.pb( X.size() );
            Kv.pb( V.size() );
        }
        else
        {
            X.pb(i);
            xx++;
            Xv.pb( V.size() );
            Xk.pb( K.size() );
        }
    }
    memset( dp, 110, sizeof dp );
    dp[0][0][0][0] = 0;
    //debug;
    for( int v = 0; v <= vv; v++ )
    {
        for( int k = 0; k <= kk; k++ )
        {
            for( int x = 0; x <= xx; x++ )
            {
                for( int i = 0; i < 2; i++ )
                {
                    int cur = dp[v][k][x][i], mv = 1000, mk = 01000, mxx = 10000;
                    if( v < vv )
                        mv =  max( 0, Vk[v] - k ) + max( 0, Vx[v] - x );
                    if( k < kk )
                        mk =  max( 0, Kv[k] - v ) + max( 0, Kx[k] - x );
                    if( x < xx )
                        mxx = max( 0, Xv[x] - v ) + max( 0, Xk[x] - k );
                    //cout << v << " " << k << " " << x << " "<< i << "  ";
                    //cout << cur << " " << mv << " " << mk << " " << mxx << endl;
                    if( v < vv )
                    {
                        dp[v+1][k][x][1] = min( dp[v+1][k][x][1], cur+mv );
                    }
                    if( k < kk && i == 0 )
                    {
                        dp[v][k+1][x][0] = min( dp[v][k+1][x][0], cur+mk );
                    }
                    if( x < xx )
                    {
                        dp[v][k][x+1][0] = min( dp[v][k][x+1][0], cur+mxx );
                    }
                }
            }
        }
    }

    cout << min( dp[vv][kk][xx][0], dp[vv][kk][xx][1]  ) << endl;

    return 0;
}




