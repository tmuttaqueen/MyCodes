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
const int len = 100001;
vector<int>val[320];
vector<pii>seg[320];
vector<int>tree[320], lazy[320], rst[320];
int qr[M];

inline void propagate( int &cn, int &l, int &r, int &ind )
{
    tree[ind][cn] = r - l + 1 - tree[ind][cn];
    if( l != r )
    {
        lazy[ind][cn<<1] = (lazy[ind][cn<<1]+1)&1;
        lazy[ind][(cn<<1)+1] = (lazy[ind][(cn<<1)+1]+1)&1;
    }
    lazy[ind][cn] = 0;
}

inline void reset( int cn, int l, int r, int ind )
{
    tree[ind][cn] = 0;
    if( l != r )
    {
        rst[ind][cn*2] = rst[ind][cn*2+1] = 1;
    }
    rst[ind][cn] = 0;
}

void update( int cn, int l, int r, int x, int ind )
{
    if( rst[ind][cn] == 1 )
        reset( cn, l, r, ind );
    if( lazy[ind][cn] )
        propagate( cn, l, r, ind );
    if( val[ind][r] < x ) return;
    if( val[ind][l] >= x )
    {
        lazy[ind][cn] = (lazy[ind][cn]+1)&1;
        propagate(cn, l, r, ind);
        return;
    }
    int m = (l+r)/2, n = cn<<1;
    if( val[ind][m] >= x )
        update( n, l, m, x, ind );
    update( n+1, m+1, r, x, ind );
    tree[ind][cn] = tree[ind][n] + tree[ind][n+1];
}

void upd( int cn, int l, int r, int x, int ind )
{
    if( rst[ind][cn] == 1 )
        reset( cn, l, r, ind );
    if( lazy[ind][cn] )
        propagate( cn, l, r, ind );
    if( x < l || x > r ) return;
    if( l == r )
    {
        tree[ind][cn] = ( tree[ind][cn] + 1 )&1;
        return;
    }
    int m = (l+r)/2, n = cn<<1;
    if( m >= x )
        upd( n, l, m, x, ind );
    else
        upd( n+1, m+1, r, x, ind );
    tree[ind][cn] = tree[ind][n] + tree[ind][n+1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, q, l, r;
        cin >> n;
        int len = sqrt(n), tot = n/len + 2;
        for( int i = 0; i < tot; i++ )
        {
            val[i].clear();
            val[i].pb(-1);
            seg[i].clear();
            seg[i].pb( mp(-1,-1) );
        }
        for( int i = 0; i < n; i++ )
        {
            cin >> l >> r;
            int s = l/len;
            val[s].pb(r);
            seg[s].pb( mp(r,l) );
        }
        for( int i = 0; i < tot; i++ )
        {
            sort( val[i].begin()+1, val[i].end() );
            sort( seg[i].begin()+1, seg[i].end() );
            int l = val[i].size();
            rst[i].clear();
            tree[i].clear();
            lazy[i].clear();
            rst[i].resize( 5*l, 0 );
            tree[i].resize( 5*l, 0 );
            lazy[i].resize( 5*l, 0 );
        }
        cin >> q;
        while(q--)
        {
            for( int i = 0; i < tot; i++ )
            {
                rst[i][1] = 1;
                reset( 1, 1, 1000, i );
            }
            int m, c = 0;
            cin >> m;
            while(m--)
            {
                cin >> qr[c++];
                int x = qr[c-1];
                int ind = x/len;
                for( int i = 0; i < ind; i++ )
                {
                    if( val[i].size()-1 > 0 )
                        update( 1, 1, val[i].size()-1, x, i );
                }
                for( int i = seg[ind].size()-1; i > 0; i-- )
                {
                    if( seg[ind][i].xx < x ) break;
                    else if( seg[ind][i].yy <= x )
                        upd(1, 1, seg[ind].size()-1, i, ind);
                }
            }
            int ans = 0;
            for( int i = 0; i < tot; i++ )
            {
                ans += tree[i][1];
            }
            cout << ans << endl;

        }


    }
    return 0;
}
