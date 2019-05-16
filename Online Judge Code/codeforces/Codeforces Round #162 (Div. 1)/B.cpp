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

intl ara[111111], prime[111111];
vector<int>fact[111111];
intl ans[111111];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        int a = ara[i];
        for( int j = 2; j*j <= a; j++ )
        {
            if( a%j == 0 )
            {
                while( a%j == 0 )
                {
                    a/=j;
                }
                fact[i].pb(j);
            }
        }
        if( a != 1 )
            fact[i].pb(a);
    }
    intl sol = 1;
    for( int i = n-1; i >= 0; i-- )
    {
        intl mx = 0;
        for( int v: fact[i] )
        {
            mx = max( mx, prime[v] );
        }
        ans[i] = mx+1;
        for( int v: fact[i] )
        {
            prime[v] = max( prime[v], ans[i] );
        }
        sol = max( sol, ans[i] );
    }

    cout << sol << endl;

    return 0;
}




