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

int a[M], b[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    string s;
    cin >> s;
    s = "#" + s;
    a[0] = 0;
    b[0] = 0;
    for( int i = 1; i < s.length(); i++ )
    {
        a[i] = a[i-1];
        b[i] = b[i-1];
        if( s[i] == 'a' ) a[i]++;
        else b[i]++;
    }
    int ans = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        for( int j = i; j < s.length(); j++ )
        {
            ans = max( ans, a[i] + b[j] - b[i] + a[ s.length()-1 ] - a[j] );
        }
    }
    cout << ans << endl;
    return 0;
}
