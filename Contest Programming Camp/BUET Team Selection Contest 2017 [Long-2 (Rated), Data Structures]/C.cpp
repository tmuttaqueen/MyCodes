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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

typedef tree < int , null_type ,less<int>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

struct comp
{
    bool operator()( const pii &a, const pii &b ) const
    {
        if( b.yy-b.xx == a.yy-a.xx )
        {
            return b.xx < a.xx;
        }
        return b.yy-b.xx < a.yy-a.xx;
    }
};

set<pii, comp>ss;
map<int, int> mm1, mm2, pos;
ordered_set os;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, q;
    cin >> n >> q;
    ss.insert( mp(1,n) );
    mm1[1] = n;
    mm2[n] = 1;
    for( int i = 0; i < q; i++ )
    {
        int x;
        cin >> x;
        if( x != 0 )
        {
            if( pos[x] == 0 )
            {
                pii a = *ss.begin();
                ss.erase( a );
                int d = ( (a.yy+a.xx+1)/2 );
                pos[x] = d;
                os.insert(d);
                mm1[a.xx] = d-1;
                mm1[d+1] = a.yy;
                mm2[d-1] = a.xx;
                mm2[a.yy] = d+1;
                ss.insert( mp( a.xx,d-1 ) );
                ss.insert( mp(d+1, a.yy ) );
                //cout << a.xx << " " << a.yy << endl;
                //what_is(x);
                //what_is(d);
            }
            else
            {
                os.erase( pos[x] );
                int d = pos[x];
                pos[x] = 0;
                pii a, b;
                a.xx = mm2[d-1];
                a.yy = d-1;
                b.xx = d+1;
                b.yy = mm1[d+1];
                ss.erase(a);
                ss.erase(b);
                ss.insert( mp( a.xx, b.yy ) );
                mm1[a.xx] = b.yy;
                mm2[b.yy] = a.xx;
                //cout << a.xx << " " << b.yy << endl;
            }

        }
        else
        {
            int a, b;
            cin >> a >> b;
            b++;
            int x = os.order_of_key(a), y = os.order_of_key(b);
            cout << y-x << endl;
        }


    }
    return 0;
}
