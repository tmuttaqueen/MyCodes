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

int ara[200005];
set<int>ss;

int main()
{
    ios::sync_with_stdio(false);
    int n, a;
    cin >> n;
    int ans = -1;
    for( int i = 0 ;i < 2*n; i++ )
    {
        cin >> ara[i];
    }
    for( int i  = 0; i < 2*n; i++ )
    {
        int a = ara[i];
        ans = max( ans, (int)ss.size() );
        if( ss.find(a) != ss.end() )
        {
            ss.erase( ss.find(a) );
        }
        else
        {
            ss.insert(a);
        }
    }

    cout << ans << endl;

    return 0;
}




