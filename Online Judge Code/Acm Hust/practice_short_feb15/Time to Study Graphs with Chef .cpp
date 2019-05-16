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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;
intl mod = 1e9+7;

long long expo( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}


map<intl, vector<intl> >from;
map<intl, intl> dp;
set<intl>ss;
vector<intl>vec;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, m, k, l1, l2, v1, v2;
    cin >> n >> m >> k;
    ss.insert(0);
    ss.insert(n+1);
    dp[0] = 1;
    for( int i = 0; i < k; i++ )
    {
        cin >> l1 >> v1 >> l2 >> v2;
        from[l2].pb(l1);
        ss.insert(l1);
        ss.insert(l2);
    }
    for( intl v: ss )
    {
        vec.pb(v);
    }
    intl inv = expo(m, mod-2, mod);

    for( int i = 1; i < vec.size(); i++ )
    {
        intl v = vec[i];
        intl prev = vec[i-1];

        vector<intl> vv = from[v];
        intl tot;
        if( v != n+1 )
            tot = (dp[prev]*expo(m, v - prev, mod))%mod;
        else
            tot = (dp[prev]*expo(m, v - prev - 1, mod))%mod;

        for( intl u: vv )
        {
            if(u==0)
            {
                tot++;
                continue;
            }
            cout << u << " to " << dp[u] << endl;
            tot += ((dp[u]*inv)%mod);
            tot %= mod;
        }
        cout << v << " " << tot  << endl;
        dp[v] = tot%mod;
    }
    //intl ans = dp[vec.size()-1]*expo( m, n+1-vec[vec.size()-1] -1, mod );

    cout << dp[n+1] << endl;
    return 0;
}
