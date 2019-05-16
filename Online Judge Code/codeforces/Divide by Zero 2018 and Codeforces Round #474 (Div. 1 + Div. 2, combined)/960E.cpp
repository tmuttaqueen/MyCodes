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
const int M = 200005;

intl odd[M], even[M], sum[M], mod = 1e9+7;
intl sz[M], val[M], ans, szeven[M], szodd[M];

vector<int>edge[M];

void dfsSZ( int u, int p )
{
    sz[u] = 1;
    szeven[u]= 1;
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        dfsSZ(v, u);
        szeven[u] += szodd[v];
        sz[u] += sz[v];
    }
    szodd[u] = sz[u] - szeven[u];
}
void solve( int u, int p )
{
    intl oo = 0, ev = 0;
    intl tot = 0;
    for( int v: edge[u] )
    {
        if( v != p )
            tot += szeven[v];
    }
    intl temp = 0;
    intl sq = 0;
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        solve(v, u);
        intl ch = szeven[v];
        (sq += ch*ch)%mod;
        oo += odd[v];
        ev += even[v];
        //cout << u << ' ' << v << ' ' << ch << " " << tot << endl;
        temp = (temp + (( tot-ch )*even[v]%mod))%mod;
    }
    oo %= mod;
    ev %= mod;
    sq %= mod;
    temp *= 2;
    (temp += ( (tot*tot%mod - sq)%mod )*(-val[u])%mod)%mod;
    odd[u] = (ev + szodd[u]*(-val[u])%mod)%mod;
    even[u] = (oo + szeven[u]*val[u]%mod)%mod;
    //cout << u << " " << temp << " even " << even[u] << " odd " << odd[u] << endl;
    (ans += temp)%mod;
    (ans += even[u]*2)%mod;
    (ans -= val[u])%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, a, b;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> val[i];
    }
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfsSZ(1, -1);
    solve(1, -1);
    cout << (ans%mod+mod)%mod << endl;
    return 0;
}
