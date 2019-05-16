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
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<int>divisor[222222];
int g[222222];
int val[222222];
vector<int>edge[222222];
int cnt[222222];
int sz[222222], dp[222222];

intl gcd( intl a, intl b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

void dfs( intl u, intl p )
{
    //what_is(u);
    //what_is(p);
    if(p != -1)
    {
        sz[u] = sz[p] + 1;
    }
    if( p != -1 )
    {
        g[u] = gcd( val[u], g[p] );
        dp[u] = g[p];
    }
    for( int x: divisor[u] )
    {
        cnt[x]++;
        if( (cnt[x] == sz[u] || cnt[x] == sz[u]-1) && u != 1  )
        {
            //what_is(x);
            dp[u] = max( x, dp[u] );
        }
        if( val[u]/x != x )
        {
            x = val[u]/x;
            cnt[x]++;
            if( (cnt[x] == sz[u] || cnt[x] == sz[u]-1) && u != 1  )
            {
                //what_is(x);
                dp[u] = max( x, dp[u] );
            }
        }
    }

    for( int v: edge[u] )
    {
        if(v != p)
        {
            dfs(v,u);
        }
    }
    for( int x: divisor[u] )
    {
        cnt[x]--;
        if( val[u]/x != x )
        {
            cnt[ val[u]/x ]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> val[i];
        for( int j = 1; j*j <= val[i]; j++ )
        {
            if( val[i]%j == 0 )
            {
                divisor[i].pb(j);
            }

        }
    }

    dp[1] = val[1];
    sz[1] = 1;
    g[1] = val[1];
    for( int i = 1; i < n; i++ )
    {
        int a,b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(1,-1);
    for( int i = 1; i <= n; i++ )
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
