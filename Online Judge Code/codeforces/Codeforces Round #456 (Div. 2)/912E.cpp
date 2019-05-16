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

vector<intl>pa, pb, na, nb;
intl mx = 1.00000005e18;

void dfs( vector<intl> &a, vector<intl> &v, intl i, intl val  )
{
    if( val > mx ){ return; }
    //what_is(i);
    //what_is(val);
    v.pb(val);
    if( a.size() > i && val <= mx/a[i] ) dfs( a, v, i, val*a[i] );
    for( int j = i+1; j < a.size(); j++ )
        if( val <= mx/a[j] )
            dfs( a, v, j, val*a[j] );
}

intl solve( intl v )
{
    intl cnt = 0;
    for( int i = 0; i < na.size(); i++ )
    {
        cnt += upper_bound( nb.begin(), nb.end(), v/na[i] )- nb.begin();
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, k, x;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> x;
        if( i&1 )
        {
            pa.pb(x);
        }
        else
        {
            pb.pb(x);
        }
    }
    cin >> k;
    dfs( pa, na, 0LL, 1LL );
    //debug;
    dfs( pb, nb, 0LL, 1LL );
    sort( na.begin(), na.end() );
    sort( nb.begin(), nb.end() );
    //cout << pa.size() << " " << na.size() << endl;
    //cout << pb.size() << " " << nb.size() << endl;
    intl l = 1, r = mx, ans = 1;
    while( l <= r )
    {
        intl m = (l+r)/2;
        if( solve(m) >= k )
        {
            ans = m;
            r = m -1;
        }
        else
            l = m +1;
    }
    cout << ans << endl;
    return 0;
}
