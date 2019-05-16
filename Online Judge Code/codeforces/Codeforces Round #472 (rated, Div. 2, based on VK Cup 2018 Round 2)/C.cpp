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

intl ara[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, u;
    cin >> n >> u;
    for( int i = 0; i < n; i++ )
        cin >> ara[i];
    sort( ara, ara+n );
    double ans = 0;
    int c = 0;
    for( int i = 0; i < n-2; i++ )
    {
        if( ara[i+2] - ara[i] > u )
        {
            c++;
        }
    }
    if( c == n-2 )
    {
        cout << -1 << endl;
        return 0;
    }
    for( int i = 0; i < n-2; i++ )
    {
        intl d = upper_bound( ara+i, ara+n, ara[i]+u ) - ara;
        d--;
        //cout << i << " " << d << endl;
        if( d < n )
        {
            ans = max( ans, 1.0 - ( ara[i+1]-ara[i] )*1.0/( ara[d] - ara[i] ) );
        }
        else
            ans = max( ans, 1.0 - ( ara[i+1]-ara[i] )*1.0/( ara[n-1] - ara[i] ) );

    }
    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}
