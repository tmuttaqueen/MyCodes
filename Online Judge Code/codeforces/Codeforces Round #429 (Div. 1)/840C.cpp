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

int n;
int ara[321], cnt[321];
intl mod = 1e9+7;
intl dp[321][321], C[321][321];
intl fact[321];

int process( int a )
{
    for( intl p = 2; p*p <= a; p++ )
    {
        intl d = p*p;
        while( a%d == 0 )
        {
            a /= d;
        }
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    fact[0] = 1;
    for( int i = 1; i <= 300; i++ )
    {
        fact[i] = ( fact[i-1]*i )%mod;
    }
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        ara[i] = process(ara[i]);
    }
    sort( ara, ara+n );
    int d = 1;
    for( int i = 0; i < n; i++ )
    {
        if( i == 0 || ara[i] == ara[i-1] )
            cnt[d]++;
        else
        {
            d++;
            cnt[d]++;
        }
    }
    sort( cnt+1, cnt+d+1 );
    reverse( cnt+1, cnt+d+1 );
    //for( int i = 1; i <= d; i++ ) cout << cnt[i] << endl;
    C[0][0] = 1;
    for( int i = 1; i <= 300; i++ )
    {
        C[i][0] = 1;
        for( int j = 1; j <= i; j++ )
        {
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    }
    dp[1][ cnt[1] -1] = fact[ cnt[1] ];
    int s = cnt[1];
    intl f = 1;
    for( int i = 2; i <= d; i++ )
    {
        int v = cnt[i];
        for( int j = 0; j <= s; j++ )
        {
            if( dp[i-1][j] == 0 ) continue;
            for( int k = 1; k <= v; k++ )
            {
                for( int x = 0; x <= k && x <= j; x++ )
                {
                    //cout << i << " - " << j-x+v-k << " j " << j << " x " << x << " k " << k << " s " << s << " s-j+1 " << s-j+1  << endl;
                    //dp[i][j-x+v-k] += dp[i-1][j]*C[j][x]%mod*C[s-j+1][v-x]%mod*fact[x]%mod*fact[v-x]%mod*C[v][x]%mod*C[v-1][k-1]%mod;
                    (dp[i][j-x+v-k] += dp[i-1][j]%mod*C[j][x]%mod*C[s-j+1][k-x]%mod*C[v-1][k-1]%mod*fact[v]%mod)%mod;
                    //dp[i][j-x+v-k] %= mod;
                }
            }
        }
        //f = f*fact[v]%mod;
        s += v;
    }
    /*for( int i = 1; i <= d; i++ )
    {
        for( int j = 0; j <= s; j++ )
            cout << "dp[" << i << "][" << j << "] : " << dp[i][j] << " ";
        cout << endl;
    }*/

    cout << dp[d][0]%mod << endl;
    return 0;
}
