#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb         long double

int tt = 1;

intl dis[100005], par[100005], ch[100005];
long double ans[100005];

vector<int>edge[100005];

void dfs( int u )
{
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v != par[u] )
        {
            dfs(v);
            ch[u] += ch[v];
        }
    }
    ch[u] += 1;
}

void dfsss(int u)
{
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v != par[u] )
        {
            long double temp = ch[u] - ch[v]-1;
            ans[v] = ans[u] + 1.0 + temp/2.0;
            dfsss(v);
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    for( int i = 2; i <= n; i++ )
    {
        intl a;
        cin >> a;
        par[i] = a;
        edge[a].pb(i);
        edge[i].pb(a);
    }
    dfs(1);
    ans[1] = 1.0;
    dfsss(1);

    cout << setprecision(6) << fixed << ans[1];
    for( int i = 2; i <= n; i++ )
    {
        cout << " " << setprecision(6) << fixed << ans[i] ;
    }
    cout << endl;
    return 0;
}




