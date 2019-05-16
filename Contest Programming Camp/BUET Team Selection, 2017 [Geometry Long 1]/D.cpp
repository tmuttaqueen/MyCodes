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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

pii point[11111];
pii seg[11111];
intl k, n, s, d;

intl solve( intl m )
{
    for( intl i = 0; i < n; i++ )
    {
        intl ss = sqrt( d*d - ( m - point[i].yy )*( m - point[i].yy ) );
        intl f1 = point[i].xx + ss, f2 = point[i].xx - ss;
        seg[i].xx = min(f1,f2);
        seg[i].yy = max(f1,f2);
    }
    intl l = -1000000000, r = -1000000000;
    intl cnt = 0;
    for( intl i = 0; i < n; i++ )
    {
        if( seg[i].xx <= r )
        {
            l = seg[i].xx;
            r = min( seg[i].yy, r );
        }
        else
        {
            l = seg[i].xx;
            r = seg[i].yy;
            cnt++;
        }
    }
    return cnt;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    intl t, caseno = 1;
    cin >> t;
    while(t--)
    {

        cin.ignore();
        cin >> k >> n >> s >> d;
        //k++;
        intl h = -2000000000;
        for( intl i = 0; i < n; i++ )
        {
            cin >> point[i].xx >> point[i].yy;
            h = max( h, point[i].yy-d );
        }
        sort( point, point+n );
        if( h > k-1 )
        {
            cout << "Case " << caseno++ << ": " << "impossible" << endl;
            continue;
        }
        intl l = k-1;
        swap(l,h);
        intl ans = -2000000000;
        //what_is(l);
        //what_is(h);
        while( l <= h )
        {
            intl m = (l+h)/2;
            intl p = solve(m);
            //what_is(m);
            //what_is(p);
            if( p <= s )
            {
                h = m-1;
                ans = m;
            }
            else
            {
                l = m+1;
            }
        }
        if( ans == -2000000000 )
        {
            cout << "Case " << caseno++ << ": " << "impossible" << endl;
        }
        else
            cout << "Case " << caseno++ << ": " << abs(ans-k) << endl;

    }
    return 0;
}
