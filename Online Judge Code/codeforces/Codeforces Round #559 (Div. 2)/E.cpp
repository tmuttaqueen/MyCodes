#include<bits/stdc++.h>

using namespace std;

#define ld             long double
#define intl           long long
#define pii            pair<int,int>
#define xx             first
#define yy             second
#define mp             make_pair
#define pb             push_back
#define SZ(x)          (int)(x).size()
#define ALL(x)         begin(x), end(x)
#define REP(i, n)      for (int i = 0; i < n; ++i)
#define FOR(i, a, b)   for (int i = a; i <= b; ++i)
#define RFOR(i, a, b)  for (int i = a; i >= b; --i)

const int MAXN = 500005, inf = 1e9+5;
const intl INF = 1e18+5;
const ld eps = 1e-9;

pii tree[4*MAXN]; int lazy[4*MAXN];

void init( int cn, int s, int e )
{
    lazy[cn] = 0;
    if( s == e )
    {
        tree[cn].xx = 0;
        tree[cn].yy = s;
        return ;
    }
    int l = cn*2, m = (s+e)/2;
    init(l, s, m);
    init(l+1, m+1, e);
    tree[cn] = min( tree[l], tree[l+1] );
}

void propagate( int cn, int s, int e )
{
    if( s != e )
    {
        lazy[cn*2] += lazy[cn];
        lazy[cn*2+1] += lazy[cn];
    }
    tree[cn].xx += lazy[cn];
    lazy[cn] = 0;
}

void update( int cn, int s, int e, int x, int y, int v )
{
    if( y < x ) return;
    if( lazy[cn] )
    {
        propagate(cn, s, e);
    }
    if( e < x || s > y ) return ;
    if( s >= x && e <= y )
    {
        lazy[cn] += v;
        propagate(cn, s, e);
        return ;
    }
    int l = cn*2, m = (s+e)/2;
    update(l, s, m, x, y, v);
    update(l+1, m+1, e, x, y, v );
    tree[cn] = min( tree[l], tree[l+1] );
}

int nxt[MAXN];
vector<int> from[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        //vector<int> ans(n+1,0);
        int n;
        cin >> n;
        vector<int> ans(n+1,0);
        for( int i = 1; i <= n; i++ ) from[i].clear();
        init(1,1,n);
        for(  int i = 1; i <= n; i++)
        {
            cin >> nxt[i];

            if( nxt[i] != -1 )
            {
                from[ nxt[i] ].push_back(i);
                if( nxt[i] != n+1 )
                    update(1, 1, n, i, i, 1);
                update(1, 1, n, i+1, nxt[i]-1, 1 );
            }
        }
        int f = 1, cur = n;
        for( int i = 1; i <= n; i++ )
        {
            pii top = tree[1];
            int v = top.yy;
            //cout << "v: " << v << " val: " << top.xx  << endl;
            ans[v] = cur--;
            if( top.xx != 0 )
            {
                f = 0;
                break;
            }
            ans.push_back(v);
            for( int u: from[v] )
            {
                update(1,1,n,u,u,-1);
            }
            update(1,1,n, v+1, nxt[v]-1, -1);
            update(1,1,n,v,v,inf);
        }
        if(f==0)
        {
            cout << -1 << endl;
        }
        else
        {
            //reverse(ans.begin(), ans.end());
            for( int i = 1; i <= n; i++ )
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}

