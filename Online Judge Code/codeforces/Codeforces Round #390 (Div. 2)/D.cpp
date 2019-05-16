#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define piii        pair<pii, intl>
#define double      long double

typedef tree < pii , null_type ,less<pii>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

struct data
{
    intl xx,yy,ind;
};

data ara[300005];

bool comp( data &a, data &b )
{
    if( a.xx == b.xx )
        a.yy < b.yy;
    return a.xx < b.xx;
}
vector<int>vec;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int x, y;
    int n, k;
    cin >> n >> k;
    ordered_set first, last;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i].xx >> ara[i].yy;
        ara[i].ind = i+1;
    }
    sort( ara, ara+n, comp );
    intl ans = 0;
    for( int i = 0; i < n; i++ )
    {
        first.insert( mp( ara[i].xx, ara[i].ind ) );
        last.insert( mp( ara[i].yy, ara[i].ind ) );
        int sa = first.order_of_key( mp( ara[i].xx, 1e9 ) );
        int d = sa - k ;
        //d = min( d, last.size()-1 );
        //what_is(sa);
        if( d >= 0 )
        {
            pii p = *(last.find_by_order( d ));
            //cout << p.xx - ara[i].xx << endl;
            if( p.xx - ara[i].xx + 1 > ans )
            {
                x = i;
                ans = max( ans, p.xx - ara[i].xx+1 );
            }
        }
    }
    if( ans == 0 )
    {
        cout << 0 << endl;
        for( int i =  1; i <= k; i++ ) cout << i << " ";
        cout << endl;
        return 0;
    }
    cout << ans << endl;

    first.clear();
    last.clear();

    for( int i = 0; i <= x; i++ )
    {
        first.insert( mp( ara[i].xx, ara[i].ind ) );
        last.insert( mp( ara[i].yy, ara[i].ind ) );
    }
    int sa = first.order_of_key( mp( ara[x].xx, 1e9 ) );
    int d = sa - k ;

    if( d >= 0 )
    {
        auto p = last.find_by_order( d );
        for( int i = 0; i < k; i++ )
        {
            vec.pb((*p).yy);
            p++;
        }
        sort( vec.begin(), vec.end() );
        for( int i = 0; i < k; i++ )
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    //cout << x << " " << y << endl;
    return 0;
}




