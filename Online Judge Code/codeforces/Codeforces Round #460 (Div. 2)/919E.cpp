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

long long expo( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

vector<int>vec;
vector<int>res;
int pos[1234567];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl a, b, p, lim;
    cin >> a >> b >> p >> lim;
    intl d = 1;
    int cyc = 0;
    pos[1] = 0;
    for( int i = 1; i < p; i++ )
    {
        d = (d*a)%p;
        cout << d << " ";
        res.pb(d);

        if( cyc == 0 && d == 1 )
        {
            cyc = i;
            break;
        }
        pos[d] = i;

    }
    cout << endl;
    for( int i = 1; i <= p; i++ )
    {
        if( b%i == 0 )
        {
            vec.pb(i);
        }
    }
    intl ans = 0;
    //cout << 10*expo(4, 10, p) << endl;
    for( intl x: vec )
    {
        intl b1 = b/x, b2 = x;
        intl inv = expo( a, p-2, p );
        intl pow = expo( inv, b2, p );
        x = pow*b1%p;
        //what_is(x);
        cout << b2 << ' ' << x << endl;
        if( x != 1 && pos[x] == 0 )
            continue;
        int d = pos[x];
        if( d > lim ) continue;
        intl l = -1, r = 1e12, ns = -1;
        while( l <= r )
        {
            intl m = (l+r)/2;
            if( p*(d+m*cyc) + b2 <= lim )
            {
                l = m+1;
                ns = m;
            }
            else
                r = m - 1;
        }

        what_is(x);
        what_is(ns);
        ans += (ns+1);
        //if( x == 1 ) ans++;

    }
    cout << ans << endl;
    return 0;
}
