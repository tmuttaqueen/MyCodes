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

int n,m, a, b;
pii a[100005], b[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    cin >> n >> m >> a >> b;
    for( int i = 0; i < n; i++)
    {
        cin >> a[i].xx;
        a[i].yy = i+1;
    }
    sort( a, a+n );
    for( int i = 0; i < m; i++ )
    {
        cin >> b[i].xx;
    }
    for( int i = 0; i < m; i++ )
    {
        cin >> b[i].yy;
    }
    int x = 1, y = 1;
    for( int i = 0; i < m; i++ )
    {
        int low = 0, high = n-1;
        while( low <= high )
        {
            int m1 = (low+high)/2;
            int m2 = m1+1;

        }
    }







    return 0;
}




