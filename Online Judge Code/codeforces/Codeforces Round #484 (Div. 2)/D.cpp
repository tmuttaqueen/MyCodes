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
pii ara[M];
multiset<int>ss;
int mm[M];

///1D BIT O(logn)
const int mx = 200002;
int bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i].xx;
        ara[i].yy = i;
        update(i, 1);
    }
    sort( ara+1, ara+n+1 );
    for( int i = 1; i <= n; i++ )
    {
        mm[i] = ara[i].xx;
    }
    ss.insert(n);
    //reverse( ara+1, ara+n+1 );
    int day = 1, ans = ara[n].xx+1;
    for( int i = n; i >= 1; i-- )
    {
        //what_is(i);
        int l = 1, r = ara[i].yy, lf = r;
        while( l <= r )
        {
            int m = (l+r)/2;
            int sum = query( ara[i].yy ) - query(m-1);
            if( sum == (ara[i].yy-m+1) )
            {
                r = m -1;
                lf = m;
            }
            else
                l = m+1;
        }
        l = ara[i].yy;
        r = n;
        int rf = l;
        while( l <= r )
        {
            int m = (l+r)/2;
            int sum = query(m) - query( ara[i].yy-1 );
            if( sum == ( m - ara[i].yy + 1) )
            {
                rf = m;
                l = m+ 1;
            }
            else
                r = m - 1;
        }
        //what_is(i);
        int d = rf - lf+1;

        update( ara[i].yy, -1 );

        ss.erase( ss.find(d) );


        if( ara[i].yy != lf )
        {
            ss.insert( ara[i].yy-lf );
        }
        if( ara[i].yy != rf )
        {
            ss.insert( -ara[i].yy+rf );
        }

        if( ss.size() == 0 )
            break;
        auto it = ss.end();
        it--;
        int v1 = *ss.begin(), v2 = *it;

        if( v1 == v2 )
        {
            if( ss.size() >= day )
            {
                day = ss.size();
                ans = ara[i-1].xx+1;
            }
            //ans = ara[i].xx;
        }
        //what_is(i);

    }
    if( n == 1 )
    {
        ans = ara[1].xx+1;
    }
    cout << ans << endl;
    return 0;
}
