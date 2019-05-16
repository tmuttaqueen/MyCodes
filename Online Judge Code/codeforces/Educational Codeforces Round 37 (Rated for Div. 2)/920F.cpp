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

int phi[M*3];
int ara[1005][1005];
vector<int>vec[1000005];

void sieve()
{
    int n = 1000000;
    for( int i = 1; i <= n; i++ ) phi[i] = i;
    phi[1] = 1;
    for( int i = 2; i <= n; i++ )
    {
        if( phi[i] == i )
        {
            for( int j = i; j <= n; j+= i )
            {
                phi[j] = phi[j]/i;
                phi[j] *= (i-1);
            }
        }
    }
    for( int i = 2; i <= n; i++ )
    {
        for( int j = i+i; j <= n; j+= i )
        {
            vec[j].pb(i);
        }
    }
}

int gcd( int a, int b )
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

intl coprime( intl p, intl x )
{
    if( x == 0 ) return 0;
    if(x == 1) return 1;
    if( p <= 1000 ) return ara[p][x];
    int s = 0;
    for( int d: vec[p] )
    {
        s += coprime( p/d, x/d );
    }
    return s;
}

intl prime( intl x, intl p )
{
    intl s = phi[p]*( x/p );
    s += coprime( p,  x%p );
    return s;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl s = 0;
    ara[1][1] = 1;

    for( int i = 1; i <= 1000; i++ )
    {
        ara[i][1] = 1;
        for( int j = 2; j <= i; j++ )
        {
            ara[i][j] = ara[i][j-1];
            if( gcd(i, j) == 1 )
            {
                ara[i][j]++;
            }
        }
    }
    sieve();
    int t, x, p, k;
    cin >> t;
    while(t--)
    {
        cin >> x >> p >> k;
        intl l = 1, r = 1e12;
        intl ans = 1;
        intl b =  prime(x, p);
        while( l <= r )
        {
            intl m = (l+r)/2;
            intl a = prime(m ,p) - b;
            //cout << a << " " <<  m << endl;
            if( a >= k )
            {
                ans = m;
                r = m  - 1;
            }
            else
                l = m + 1;

        }
        cout << ans << endl;
    }
    return 0;
}
