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

int n;
vector<int>edge[200005];
int val[200005];
int vis[200005];
int one[200005];
vector<int>ver;
int len[200005];

void dfs( int u )
{
    vis[u] = 1;
    if( edge[u].size() == 1 && u != 1 )
    {
        len[u] = 0;
        val[u] = 1;
        return;
    }
    int x;
    for( int i = 0; i < edge[u].size(); i++ )
    {

        int v = edge[u][i];
        if( vis[v] == 0 )
        {
            dfs(v);
            if( val[v] == 1 )
            {
                if( val[u] == 0 )
                    x = v;
                val[u]++;
            }
            if( i == edge[u].size() - 1 && val[u] == 1 )
            {
                len[u] = len[x] + 1;
            }
        }

    }
}


int main()
{
    ios::sync_with_stdio(false);
    filein;
    cin >> n;
    for( int i = 1; i< n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }

    dfs(1);
    int ans = 1e9;
    //debug;
    for( int i = 1; i<= n; i++ )
    {
        map<int, int>mm;
        for( int j = 0; j < edge[i].size(); j++ )
        {
            if( val[edge[i][j]] == 1 )
            {
                one[i]++;
                mm[len[ edge[i][j] ]]++;
            }

        }
        if( one[i] == edge[i].size() && mm.size() == 2  )
        {
            cout << i << endl;
            pii a = *(mm.begin());
            mm.erase( mm.begin() );
            pii b = *(mm.begin());
            int x = -1;
            if( a.yy == 1 && b.yy == 1)
                x = a.xx + b.xx + 2;
            else if( a.yy == edge[i].size() - 1 )
            {
                x = a.xx + b.xx + 2;
            }
            else if( b.yy == edge[i].size() - 1  )
            {
                x = a.xx + b.xx + 2;
            }
            if( x != -1 )
            {
                ans = min(ans, x);
            }
        }
        mm.clear();

    }

    if( ans == (1e9) )
    {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;


    return 0;
}
