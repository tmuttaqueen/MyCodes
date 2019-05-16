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

int p[2000];
intl ans[2000][3];
intl mod = 1e9+7;


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> p[i];
    ans[0][1] = 0;
    ans[0][2] = 1;
    for( int i = 1; i < n; i++ )
    {
        ans[i][1] = (ans[i-1][2] + 1)%mod;
        ans[i][2] = ((2*ans[ i ][1] - ans[ p[i]-1 ][1] + 1 )%mod+mod)%mod;
        //cout << ans[i][1] << " " << ans[i][2] << endl;
    }
    cout << (ans[n-1][2] + 1)%mod << endl;
    return 0;
}




