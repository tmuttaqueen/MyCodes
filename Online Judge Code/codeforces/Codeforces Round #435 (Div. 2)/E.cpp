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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl a[111111], b[111111];

set<intl>l, r;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, q;
    cin >> n >> m >> q;
    for( int i =1; i <= n; i++ ) cin >> a[i];
    for( int i = 1; i <= m; i++ ) cin >> b[i];

    intl x = 0, t = 1, y = 0;
    for( int i = 1; i <= n; i++ )
    {
        x += t*a[i];
        t *= (-1);
    }
    t = 1;
    for( int i = 1; i <= n; i++ )
    {
        y += t*b[i];
        t *= (-1);
    }







    return 0;
}
