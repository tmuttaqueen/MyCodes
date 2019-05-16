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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int row[1111], col[1111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        row[i] = 1;
        col[i] = 1;
    }
    row[1] = row[n] = col[1] = col[n] = 0;
    for( int i = 1; i <= m; i++ )
    {
        int a, b;
        cin >> a >> b;
        row[a] = col[b] = 0;
    }
    int ans = 0;
    for( int i =1; i <= n; i++ )
    {
        //if( row[i] == col[i] && row[i] == 1 )
           // row[i] = 0;
        ans += row[i];
        ans += col[i];
    }
    if( n%2 )
    {
        if( row[n/2+1] == col[n/2+1] && row[n/2+1] == 1 )
        {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
