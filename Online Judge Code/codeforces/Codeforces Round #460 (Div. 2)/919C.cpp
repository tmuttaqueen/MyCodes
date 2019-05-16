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

string s[2005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, k;
    cin >> n >> m >> k;
    for( int i = 0; i < n; i++ )
    {
        cin >> s[i];
    }
    int ans = 0;
    for( int i = 0; i < n; i++ )
    {
        int c = 0;
        for( int j = 0; j < m; j++ )
        {
            if( s[i][j] == '.' )
            {
                c++;
            }
            else
            {
                c = 0;
            }
            if( c >= k ) ans++;
        }
    }
    for( int j = 0; j < m; j++ )
    {
        int c = 0;
        for( int i = 0; i < n; i++ )
        {
            if( s[i][j] == '.' )
            {
                c++;
            }
            else
            {
                c = 0;
            }
            if( c >= k ) ans++;
        }
    }
    if( k == 1 ) ans/=2;
    cout << ans << endl;
    return 0;
}
