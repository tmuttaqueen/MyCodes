#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

intl tree[4*100005], lazy[4*100005];
bool flag[4*100005];

intl gcd( intl a, intl b )
{
    if( b == 0 ) return a;
    return gcd(b, a%b);
}

void relax( int cn, int a, int b )
{
    //debug;
    tree[cn] = lazy[cn]*(b-a+1);
    if( a != b )
    {
        int l = cn<<1;
        int r = l+1;
        lazy[l] = lazy[r] = lazy[cn];
        flag[l] = flag[r] = 1;
    }
    flag[cn] = 0;
    return;
}

void update( int cn, int s, int e, int x, int y, int v )
{
    if( flag[cn] )
        relax( cn, s, e );
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] = v;
        relax( cn, s, e );
        return;
    }
    int m = (s+e)>>1, l = cn<<1;
    int r = l+1;
    update( l, s, m, x, y, v );
    update( r, m+1, e, x, y, v );
    tree[cn] = tree[l] + tree[r];
    return;
}

intl query( int cn, int s, int e, int x, int y )
{
    if( flag[cn] )
        relax( cn, s, e );
    if( e < x || s > y ) return 0;
    if( s >= x && e <= y ) return tree[cn];
    int m = (s+e)>>1;
    intl l1 = query( cn<<1, s, m, x, y );
    intl l2 = query( (cn<<1) + 1, m+1, e, x, y );
    return l1+l2;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        memset( tree, 0, sizeof(tree) );
        memset( flag, 0, sizeof(flag) );
        int n, q, a, x, y, v;
        cin >> n >> q;
        cout << "Case " << caseno++ << ":\n";
        while(q--)
        {
            cin >> a >> x >> y;
            if( a == 1 )
            {
                cin >> v;
                update( 1, 1, n, x+1, y+1, v );
            }
            else
            {
                intl s = query( 1, 1, n, x+1, y+1 );
                intl p = (y-x+1);
                intl g = gcd(s, p);
                if( p != g )
                    cout << s/g << "/" << p/g << "\n";
                    //printf("%lld/%lld\n", s/g, p/g );
                else
                    cout << s/g << "\n";
                    //printf("%lld\n", s/g);
            }
            //cout << a << "  " << x << "  " << y << "   " << v << endl;
        }
    }

    return 0;
}


