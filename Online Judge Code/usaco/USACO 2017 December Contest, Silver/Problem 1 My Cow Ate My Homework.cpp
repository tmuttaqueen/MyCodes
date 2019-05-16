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
#define filein      freopen("homework.in", "r", stdin)
#define fileout     freopen("homework.out", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;


vector<int>vec, mn;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    fileout;
    int n, a;
    intl s = 0;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        s += a;
        vec.pb(a);
    }
    int m = 1000000000;
    for( int i = n-1; i >= 0; i-- )
    {
        m = min(m, vec[i] );
        mn.pb(m);
    }
    reverse( mn.begin(), mn.end() );
    intl s1 = 0;
    double mx = 0;
    for( int i = 1; i <= n-2; i++ )
    {
        s1 += vec[i-1];

        intl sum = s - s1 - mn[i];
        //cout << s << " " << s1 << " " << mn[n-i-1] << endl;
        double c = n - (i+1);
        mx = max( mx, sum/c );
    }
    //what_is(mx);
    s1 = 0;
    for( int i = 1; i <= n-2; i++ )
    {
        s1 += vec[i-1];
        intl sum = s - s1 - mn[i];
        double c = n - (i+1);
        //cout << s << " " << s1 << " " << mn[n-i-1] << endl;
        //cout << sum << " " << c << endl;
        if( abs(sum/c-mx) <= 0.00000000001  )
        {
            cout << i << endl;
        }
    }
    return 0;
}
