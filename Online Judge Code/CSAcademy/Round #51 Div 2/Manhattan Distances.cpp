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
const int M = 345678;

int ara[33];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int a = 0;
        for( int i = 0; i < 3; i++ )
        {
            cin >> ara[i];
            a += ara[i];
        }
        if( a%2 )
        {
            cout << "-1" << endl;
            continue;
        }
        a /= 2;
        sort( ara, ara+3 );
        int p = ara[2], r = ara[1], q = ara[0];
        if( p == q+r )
        {
            cout << "0 0 " << q << " 0 " << q+r << " 0" << endl;
            continue;
        }
        if( q+r < p || r+p < q+2 )
        {
            cout << "-1" << endl;
            continue;
        }
        int x1 = p - 1, y1 = 1, y2 = a - x1, x2 = r - y2;
        cout << "0 0 " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    return 0;
}
