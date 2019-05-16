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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

intl ara[M], p[M];
vector<pii>vec;
vector<intl> val;
intl n, t;
int ispos( intl m )
{
    //what_is(m);
    //what_is(n);
    vec.clear();
    for( int i = 1; i <= n; i++ )
    {
        if( p[i] >= m )
        {
            //cout << p[i] << " " << ara[i] << endl;
            vec.pb( mp( ara[i], i ) );
        }
    }
    if( vec.size() < m ) return 0;
    sort( vec.begin(), vec.end() );
    intl tot = 0;
    for( int i = 0; i < m; i++ )
    {
        tot += vec[i].xx;
    }
    if( tot <= t )
    {
        val.clear();
        for( int i = 0; i < m; i++ )
        {
            val.pb( vec[i].yy );
        }
    }
    return tot <= t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl ans = 0;
    cin >> n >> t;
    for( int i = 1; i <= n; i++ )
    {
        cin >> p[i] >> ara[i];
    }
    intl l = 0, r = n;
    while( l <= r )
    {
        intl m = (l+r)/2;
        int f = ispos(m);
        if(f)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << endl;
    cout << val.size() << endl;
    for( int i = 0; i < val.size(); i++ )
    {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}
