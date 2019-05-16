#include <bits/stdc++.h>

using namespace std;

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

const int mx = 100005;


vector<int>adj[mx], a[mx], b[mx];
vector<int>cost(mx), red(mx), vis(mx);
int n, k;

void dfs( int u )
{
    vis[u] = 1;
    for( int i = 0; i < adj[u].size(); i++ )
    {
        int v = adj[u][i];
        if( !vis[v] )
        {
            cost[v] = cost[u] + a[u][i];
            red[v] = red[u] + b[u][i];
            dfs(v);
        }

    }
}

bool is_pos( int d, int lim)
{
    intl temp = 0;
    for( int i = 2; i <= n; i++ )
    {
        if( d <= cost[i] )
        {
            if( d >= red[i] )
                temp += cost[i] - d;
            else
                return 0;
        }

    }
    what_is(d);
    what_is(temp);
    what_is(lim);
    return temp <= lim;
}

int main()
{
    //ios::sync_with_stdio(false);
    filein;
    int x,y,p,q;
    cin >> n >> k;
    for( int i = 1; i < n; i++ )
    {
        scanf("%d %d %d %d", &x, &y, &p, &q);
        adj[x].pb(y);
        adj[y].pb(x);
        a[x].pb(p);
        a[y].pb(p);
        b[x].pb(q);
        b[y].pb(q);
    }
    cost[1] = red[1] = 0;
    dfs(1);
    //debug;
    int mn = 0, mx = 0;
    for( int i = 2; i <= n; i++  )
    {
        cout << cost[i] << ' ' << red[i] << endl;
        mn = max(mn, red[i]);
        mx = max(mx, cost[i]);
    }
    int l = mn, h = mx;
    //cout << " l " << l <<  "  h " << h << endl;
    int ans = h;
    while( l <= h )
    {
        int m = (l+h)/2;
        //what_is(m);
        if( is_pos(m, k) )
        {
            //what_is(m);
            h = m - 1;
            ans = m;
            //what_is(ans);
        }
        else
            l = m+1;
        //what_is(m);
    }
    cout << ans << endl;
    return 0;
}




