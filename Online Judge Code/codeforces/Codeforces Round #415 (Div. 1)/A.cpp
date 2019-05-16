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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

intl ara[SZ], p[SZ];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    intl d = 1;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        p[i] = d;
        d = (2*d)%mod;
    }
    sort( ara, ara + n );
    intl ans = 0;
    for( int i = n-1; i >= 0; i-- )
    {
        ans = (ans+ ara[i]*(p[i]-1) )%mod;
    }
    for( int i = 0; i < n; i++ )
    {
        ans = (ans-ara[i]*(p[n-i-1]-1) )%mod;
    }
    cout << (ans+mod)%mod << endl;
    return 0;
}




